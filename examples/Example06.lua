--[[
---Example 6: dice drop---
This example is a series of functions that create osg objects and
bullet rigid body objects. The simulation is comprised of a static 
floor object, and two dice objects. The dice will collide resulting
in one flying off the floor surface and downard forever. Please read
other examples if you have questions.
]]--

require("luabullet")
require "AddAppDirectory"
AddAppDirectory()
runfile[[includes/simpleLights.lua]]

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

local function createDie(bulletWorld, pos)
	local dieOSG = MatrixTransform{
		Transform{
			position = pos,
			Model("../assets/dice.ive")
		}
	}
	local dieRigidBody = osgbDynamics.createRigidBody{
		-- by default, shapeType is a box if not specified
		sceneGraph = dieOSG,
		mass = 1.0,
		restitution = 1.0
	}
	bulletWorld:addRigidBody(dieRigidBody)
	RelativeTo.World:addChild(dieOSG)
end

local physicsTable = initPhysics()
local bulletWorld = physicsTable.dynamicsWorld

function createFloor(bulletWorld)
	local floorOSG = MatrixTransform{
		Transform{
			position = {0,0,0},
			Model[[../assets/floor.ive]]
		}
	}
	local floorRigidBody = osgbDynamics.createRigidBody{
		sceneGraph = floorOSG,
		mass = 0.0,
		restitution = 0.5
	}
	bulletWorld:addRigidBody(floorRigidBody)
	RelativeTo.World:addChild(floorOSG)
end

--create two simple osgObjects that get added to our bulletWorld (dice)
createDie(bulletWorld, {1.75, 5, -4})
createDie(bulletWorld, {0, 2, -4})
createFloor(bulletWorld)

local function startBulletSimulation()
	Actions.addFrameAction(function()
		-- wait 3 seconds before starting simulation
		Actions.waitSeconds(3)
		while true do
			local elapsed_time = Actions.waitForRedraw()
			bulletWorld:stepSimulation(elapsed_time)
		end
	end)
end

startBulletSimulation()