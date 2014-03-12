require("luabullet")
require "AddAppDirectory"
AddAppDirectory()
runfile[[../simpleLights.lua]]
runfile[[../bitwise_inclusive_or.lua]]

local device = gadget.PositionInterface("VJWand")

local function initPhysics()
	constructionInfo = bullet.btDefaultCollisionConstructionInfo()
	collisionConfiguration = bullet.btDefaultCollisionConfiguration(constructionInfo)
	dispatcher = bullet.btCollisionDispatcher(collisionConfiguration)
	solver = bullet.btSequentialImpulseConstraintSolver()
	--Declare broadphase collision algorithm (btDbvtBroadphase)
	-- other algorithms include: bt32BitAxisSweep3, btAxisSweep3
	broadphase = bullet.btDbvtBroadphase()
	dynamicsWorld = bullet.btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfiguration)
	--set gravity (currently -9.8 meters in the Y direction)
	dynamicsWorld:setGravity(bullet.btVector3(0, -9.8, 0))
	--Not needed, but changes all collisions with a gimpact trimesh to be solved with gimpact.
	--bullet.btGImpactCollisionAlgorithm.registerAlgorithm(dispatcher)
	return dynamicsWorld
end

function createBrickWall()
	local brickWall = Transform{}
	local brick = Model[[../../assets/brick.ive]]
	local brickLength = brick:getBound():radius()*2
	local bricks_wide = 10
	local bricks_high = 10
	local pos_y = 0
	local pos_z = 0
	-- For each row
	for j=1, bricks_high do
		-- Stagger odd rows
		if j%2 == 0 then pos_x = 0 else pos_x = brickLength/3 end
		-- For each brick in a row
		for i=1, bricks_wide do
			local newBrick = MatrixTransform{
				Transform{
					position = {pos_x,pos_y,pos_z},
					brick,
				}
			}
			local brickRigidBody = osgbDynamics.createRigidBody{
				--Declare shape type of object (box primitive)
				-- others include: TRIANGLE_MESH_SHAPE_PROXYTYPE,CONVEX_HULL_SHAPE_PROXYTYPE, GIMPACT_SHAPE_PROXYTYPE
				shapeType = bullet.btBroadphaseProxy.BOX_SHAPE_PROXYTYPE,
				sceneGraph = newBrick,
				mass = 1.0,
				restitution = 0.5
			}
			--add brickRigidBody to bulletWorld
			bulletWorld:addRigidBody(brickRigidBody)
			brickWall:addChild(newBrick)
			pos_x = pos_x + (brickLength*.90)
		end
		pos_y = pos_y + brickLength/2.7
	end
	RelativeTo.World:addChild(brickWall)
end

local function createFloor()
	local floorObj = MatrixTransform{
		Transform{
			position = {0,0,0},
			Model[[../../assets/floor.ive]]
		}
	}
	local floorRigidBody = osgbDynamics.createRigidBody{
		sceneGraph = floorObj,
		mass = 0.0,
		restitution = 0.5
	}
	bulletWorld:addRigidBody(floorRigidBody)
	RelativeTo.World:addChild(floorObj)
end

local function createKinematicTeapot(startingPos)
	local root = MatrixTransform{
		Transform{
			position = startingPos,
			scale = 0.3,
			Model("../../assets/teapot.osg")
		}
	}
	-- this differs slightly from the C++ (see RigidBody.cpp for details on what can be passed in)
	local body = osgbDynamics.createRigidBody{
		sceneGraph = root,
		-- Declare shape type for non primitive objects - use GIMPACT_SHAPE_PROXYTYPE (like our teapot)
		shapeType = bullet.btBroadphaseProxy.GIMPACT_SHAPE_PROXYTYPE,
		mass = 1.0,
		restitution = 1.0
	}
	--set KINEMATIC flag for body (required if you want to move the body manually)
	body:setCollisionFlags(bitor(body:getCollisionFlags(), bullet.btCollisionObject.CF_KINEMATIC_OBJECT))
	-- disable deactivation for body (we always want to check for collisions for the body)
	body:setActivationState(bullet.btCollisionObject.DISABLE_DEACTIVATION)
	--add body to bulletWorld
	bulletWorld:addRigidBody(body)
	return root, body
end

--create a "bulletWorld" main object to handle bullet physics & objects
bulletWorld = initPhysics()
createFloor()
createBrickWall()
teapot_osg, teapotRigidBody = createKinematicTeapot(device.position)
--add teapot_osg to world
RelativeTo.World:addChild(teapot_osg)

--REQUIRED: add a frame action to step the simulation based on dt
Actions.addFrameAction(function()
	while true do
		elapsed_time = Actions.waitForRedraw()
		bulletWorld:stepSimulation(elapsed_time)
	end
end)

--OPTIONAL: add a frame action to set teapot position to wand position (for interaction)
Actions.addFrameAction(function()
	while true do
		local xform = bullet.btTransform()
		local rotMatrixOfWand = device.matrix:getRotate()
		local quat = bullet.btQuaternion(rotMatrixOfWand:x(),rotMatrixOfWand:y(),rotMatrixOfWand:z(),rotMatrixOfWand:w())
		teapotRigidBody:getMotionState():getWorldTransform(xform)
		local origin = xform:getOrigin()
		local newOrigin = bullet.btVector3(device.position:x(), device.position:y(), device.position:z())
		xform:setOrigin(newOrigin)
		xform:setRotation(quat)
		teapotRigidBody:getMotionState():setWorldTransform(xform)
		Actions.waitForRedraw()
	end
end)

