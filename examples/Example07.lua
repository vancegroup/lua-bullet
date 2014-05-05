--[[
---Example 7: falling brick wall with teapot---
This example is a series of functions that create osg objects and
bullet rigid body objects. The simulation is comprised of a static 
floor object, a multitude of brick objects and a teapot kinematic object. 
The teapot is tied to the wand and can push/move bricks on the floor.
Please read other examples if you have questions.
]]--

require("luabullet")
require "AddAppDirectory"
AddAppDirectory()
runfile[[includes/simpleLights.lua]]
runfile[[includes/bitwise_inclusive_or.lua]]

local device = gadget.PositionInterface("VJWand")

local function initPhysics()
	initTable = {}
	initTable.collisionConfiguration = bullet.btDefaultCollisionConfiguration()
	initTable.dispatcher = bullet.btCollisionDispatcher(initTable.collisionConfiguration)
	initTable.solver = bullet.btSequentialImpulseConstraintSolver()
	--Declare broadphase collision algorithm (btDbvtBroadphase)
	-- other algorithms include: bt32BitAxisSweep3, btAxisSweep3
	initTable.broadphase = bullet.btDbvtBroadphase()
	initTable.dynamicsWorld = bullet.btDiscreteDynamicsWorld(initTable.dispatcher, initTable.broadphase, initTable.solver, initTable.collisionConfiguration)
	--set gravity (currently -9.8 meters in the Y direction)
	initTable.dynamicsWorld:setGravity(bullet.btVector3(0, -9.8, 0))
	--Not needed, but changes all collisions with a gimpact trimesh to be solved with gimpact.
	--bullet.btGImpactCollisionAlgorithm.registerAlgorithm(dispatcher)
	return initTable
end

function createBrickWall(bulletWorld)
	local brickWall = Transform{}
	local brick = Model[[../assets/brick.ive]]
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

local function createFloor(bulletWorld)
	local floorObj = MatrixTransform{
		Transform{
			position = {0,0,0},
			Model[[../assets/floor.ive]]
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

local function createKinematicBunny(bulletWorld,startingPos)
	local bunnyOSG = MatrixTransform{
		Transform{
			position = startingPos,
			scale = 2,
			Model[[../assets/bunny-1500.osg]]
		}
	}
	local bunnyRigidBody = osgbDynamics.createRigidBody{
		sceneGraph = teapotOSG,
		shapeType = bullet.btBroadphaseProxy.GIMPACT_SHAPE_PROXYTYPE,
		mass = 1.0,
		restitution = 1.0
	}
	bunnyRigidBody:setCollisionFlags(bitor(bunnyRigidBody:getCollisionFlags(), bullet.btCollisionObject.CF_KINEMATIC_OBJECT))
	bunnyRigidBody:setActivationState(bullet.btCollisionObject.DISABLE_DEACTIVATION)
	bulletWorld:addRigidBody(bunnyRigidBody)
	RelativeTo.World:addChild(bunnyOSG)
	return bunnyRigidBody
end

local physicsTable = initPhysics()
local bulletWorld = physicsTable.dynamicsWorld

createFloor(bulletWorld)
createBrickWall(bulletWorld)
local bunnyRigidBody = createKinematicBunny(bulletWorld,device.position)

Actions.addFrameAction(function()
	while true do
		local xform = bullet.btTransform()
		local rotMatrixOfWand = device.matrix:getRotate()
		local quat = bullet.btQuaternion(rotMatrixOfWand:x(),rotMatrixOfWand:y(),rotMatrixOfWand:z(),rotMatrixOfWand:w())
		bunnyRigidBody:getMotionState():getWorldTransform(xform)
		local origin = xform:getOrigin()
		local newOrigin = bullet.btVector3(device.position:x(), device.position:y(), device.position:z())
		xform:setOrigin(newOrigin)
		xform:setRotation(quat)
		bunnyRigidBody:getMotionState():setWorldTransform(xform)
		Actions.waitForRedraw()
	end
end)

local function startBulletSimulation()
	Actions.addFrameAction(function()
		while true do
			local elapsed_time = Actions.waitForRedraw()
			bulletWorld:stepSimulation(elapsed_time)
		end
	end)
end

startBulletSimulation()


