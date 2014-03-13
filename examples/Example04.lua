--[[
---Example 4: single object with static plane in the "bulletWorld"---
In this example we will replace the floor model with a static plane. However,
we will not use and OSG object to visualize the floor (static plane will be invisible).
The static plane will extend throughout the dimentions of our "bulletWorld".
Only new content in this example will be explained. Please see previous 
tutorial(s) for others.
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


local physicsTable = initPhysics()
local bulletWorld = physicsTable.dynamicsWorld

local sphereOSG = MatrixTransform{
	Transform{
		position = {0,3,0},
		Sphere{radius = 0.125}
	}
}

local sphereRigidBody = osgbDynamics.createRigidBody{
	sceneGraph = sphereOSG,
	mass = 1.0,
	restitution = 0.5
}


--TODO: these need to be global at the moment
--create a static plane (floor object) - set for pos Y direction
collisionShape = bullet.btStaticPlaneShape(bullet.btVector3(0, 1, 0), 0)
--create motionstate for constructing static plane rigid body
motionState = osgbDynamics.MotionState()
--create a bullet.btRigidBody.btRigidBodyConstructionInfo(mass, motionState, collisionShape, inertia)
rigidBodyConstructorInfo = bullet.btRigidBody.btRigidBodyConstructionInfo(0.0, motionState, collisionShape, bullet.btVector3(0.0, 0.0, 0.0))
--create rigid body for the static plane by passing the rigidBodyConstructorInfo object
staticPlaneRigidBody = bullet.btRigidBody(rigidBodyConstructorInfo)

--add the object rigid bodies to the "bulletWorld"
bulletWorld:addRigidBody(sphereRigidBody)
bulletWorld:addRigidBody(staticPlaneRigidBody)

--add osg objects to the VRJuggLua world (so we can see them)
RelativeTo.World:addChild(sphereOSG)

local function startBulletSimulation()
	Actions.addFrameAction(function()
		while true do
			local elapsed_time = Actions.waitForRedraw()
			bulletWorld:stepSimulation(elapsed_time)
		end
	end)
end

startBulletSimulation()