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
	worldAabbMin = bullet.btVector3(-10000, -10000, -10000)
	worldAabbMax = bullet.btVector3(10000, 10000, 10000)
	inter = bullet.btAxisSweep3(worldAabbMin, worldAabbMax, 1000)
	dynamicsWorld = bullet.btDiscreteDynamicsWorld(dispatcher, inter, solver, collisionConfiguration)
	dynamicsWorld:setGravity(bullet.btVector3(0,-9.8, 0))
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
				shapeType = bullet.btBroadphaseProxy.BOX_SHAPE_PROXYTYPE,
				sceneGraph = newBrick,
				mass = 10.0,
				restitution = 1
			}
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
		restitution = 0.0
	}
	bulletWorld:addRigidBody(floorRigidBody)
	RelativeTo.World:addChild(floorObj)
end

local function createKinematicTeapot(bw, startingPos)
	local root = MatrixTransform{
		Transform{
			position = startingPos,
			--scale = 0.3,
			--Model("../../assets/teapot.osg")
			Sphere{
				radius = .125
			}
		}
	}
	-- this differs slightly from the C++ (see RigidBody.cpp for details on what can be passed in)
	local body = osgbDynamics.createRigidBody{
		sceneGraph = root,
		--shapeType = bullet.btBroadphaseProxy.TRIANGLE_MESH_SHAPE_PROXYTYPE,
		-- This should be used for concave shapes? (like a teapot)
		--shapeType = bullet.btBroadphaseProxy.GIMPACT_SHAPE_PROXYTYPE,
		-- This should be used for a convex hull shapes (like a sphere)
		--shapeType = bullet.btBroadphaseProxy.CONVEX_HULL_SHAPE_PROXYTYPE,
		mass = 1.0,
		restitution = 1.0
	}
	--not sure about parameters here: see http://www.bulletphysics.org/Bullet/phpBB3/viewtopic.php?f=9&t=7195
	body:setCollisionFlags(bitor(body:getCollisionFlags(), bullet.btCollisionObject.CF_KINEMATIC_OBJECT))
	body:setActivationState(bullet.btCollisionObject.DISABLE_DEACTIVATION)
	bw:addRigidBody(body)
	return root, body
end

local function setKinematicBodyAtWand(body)
	--get body position
	local xform = bullet.btTransform()
	body:getMotionState():getWorldTransform(xform)
	local origin = xform:getOrigin()
	--set new pos based on last pos
	local wandDelta = device.position - lastWandPos
	local newOrigin = bullet.btVector3(wandDelta:x()+origin:getX(), wandDelta:y()+origin:getY(), wandDelta:z()+origin:getZ())
	xform:setOrigin(newOrigin)
	body:getMotionState():setWorldTransform(xform)
	lastWandPos = device.position
end

lastWandPos = device.position
--create a "bulletWorld" main object to handle bullet physics & objects
bulletWorld = initPhysics()
createFloor()
createBrickWall()
teapot_osg, teapotRigidBody = createKinematicTeapot(bulletWorld, device.position)
--add teapot_osg to world
RelativeTo.World:addChild(teapot_osg)

--add a frame action to step the simulation based on dt
Actions.addFrameAction(function()
	-- wait 3 seconds before starting simulation
	Actions.waitSeconds(3)
	while true do
		setKinematicBodyAtWand(teapotRigidBody)
		elapsed_time = Actions.waitForRedraw()
		bulletWorld:stepSimulation(elapsed_time)
	end
end)

