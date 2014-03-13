--[[
---Example 2: adding an object to the "bulletWorld"---
This example will create a sphere object and add it to the "bulletWorld".
When the simulation is started, our object will fall downwards, forever. 
Only new in this example will be explained. Please see previous tutorial(s) for others.
]]--

require("luabullet")

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

--First we create a simple osg object.
local sphereOSG = MatrixTransform{
	Transform{
		position = {0,3,0},
		Sphere{radius=.125}
	}
}
--Next we create a bullet RigidBody. The "sceneGraph" parameter is our osg object.
local sphereRigidBody = osgbDynamics.createRigidBody{
	sceneGraph = sphereOSG,
	mass = 1.0,
	restitution = 0.5
}

--Once the rigid body is created, we add it to our bulletWorld
bulletWorld:addRigidBody(sphereRigidBody)
--For our object to appear, we must add it to the OSG world as well. 
RelativeTo.World:addChild(sphereOSG)

local function startBulletSimulation()
	Actions.addFrameAction(function()
		while true do
			local elapsed_time = Actions.waitForRedraw()
			bulletWorld:stepSimulation(elapsed_time)
		end
	end)
end

--experiment by taking out the following line, then running it when VRJuggLua loads.
startBulletSimulation()