--[[
---Example 1: Creating the "bulletWorld"---
This example creates a "bulletWorld" using the initPhyics() function. This is required to interact with a Bullet physics simulation. 
Keep in mind, you won't actually see anything in the simulation window, as most of the work sets stuff up in the background.
]]--

--First the lua bullet library must be imported
require("luabullet")

--[[
The initPhysics() function creates a number of different bullet objects and stores them in a lua table.
Normally, you shouldn't have to touch this function, just be sure to call it so you can reference the "bulletWorld".
Within this function you can change the type of collision algorithms Bullet uses. Additionally you can change the direction 
intensity of gravity.
]]--

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

--[[
Next we call the initPhysics() function and store the initTable in a variable called physicsTable.
Normally, you will only need to create a reference to the bulletWorld variable (line 39)
]]--

local physicsTable = initPhysics()
local bulletWorld = physicsTable.dynamicsWorld

--[[
startBulletSimulation() is a function that adds a frame action to VRJuggLua.
For each frame, a call is made to step the bullet simulation (line 51).
If you don't call the function, the simulation will not run. 
]]--

local function startBulletSimulation()
	Actions.addFrameAction(function()
		while true do
			local elapsed_time = Actions.waitForRedraw()
			bulletWorld:stepSimulation(elapsed_time)
		end
	end)
end

--be sure to call this function to start the simulation!
startBulletSimulation()

print("The Bullet Simulation has started!")