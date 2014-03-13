--[[
---Example 3: multiple objects in the "bulletWorld"---
In this example we will expand on the previous tutorial by 
adding a floor for our sphere object to collide with. 
We will add a floor object that will be static,  meaning that
it will not move. Only new content in this example will be explained. 
Please see previous tutorial(s) for others.
]]--
require("luabullet")
--add require and function call to find local files
require "AddAppDirectory"
AddAppDirectory()
--add simple OSG Lights
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

local physicsTable = initPhysics()
local bulletWorld = physicsTable.dynamicsWorld

local sphereOSG = MatrixTransform{
	Transform{
		position = {0,2,0},
		Sphere{radius = 0.125}
	}
}

local sphereRigidBody = osgbDynamics.createRigidBody{
	sceneGraph = sphereOSG,
	mass = 1.0,
	restitution = 0.5
}

--[[
create a new OSG node object for the floor. 
This time we will load a model of a floor.
]]--
local floorOSG = MatrixTransform{
	Transform{
		position = {0,0,0},
		Model[[../assets/floor.ive]]
	}
}

--[[
create a rigid body of the floorOSG
Notice how mass is set to zero, this is how we tell bullet we 
want the object to be static (won't move).
]]--
local floorRigidBody = osgbDynamics.createRigidBody{
	sceneGraph = floorOSG,
	mass = 0.0,
	restitution = 0.5
}

--add the object rigid bodies to the "bulletWorld"
bulletWorld:addRigidBody(sphereRigidBody)
bulletWorld:addRigidBody(floorRigidBody)

--add osg objects to the VRJuggLua world (so we can see them)
RelativeTo.World:addChild(sphereOSG)
RelativeTo.World:addChild(floorOSG)


local function startBulletSimulation()
	Actions.addFrameAction(function()
		while true do
			local elapsed_time = Actions.waitForRedraw()
			bulletWorld:stepSimulation(elapsed_time)
		end
	end)
end

startBulletSimulation()