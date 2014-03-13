--[[
---Example 5: object manipulation in the "bulletWorld"---
In this example we will create a function that moves a teapot to the 
location of our virtual wand. Note: There will be no other objects in 
this example. Only new content in this example will be explained. 
Please see previous tutorial(s) for others.
]]--

require("luabullet")
require "AddAppDirectory"
AddAppDirectory()
runfile[[includes/simpleLights.lua]]

--include a helper file to do bitwise OR operation (gives us access to "bitor" function used later on)
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


local physicsTable = initPhysics()
local bulletWorld = physicsTable.dynamicsWorld

local teapotOSG = MatrixTransform{
	Transform{
		position = startingPos,
		scale = 0.3,
		Model("../assets/teapot.osg")
	}
}

local teapotRigidBody = osgbDynamics.createRigidBody{
	sceneGraph = teapotOSG,
	shapeType = bullet.btBroadphaseProxy.GIMPACT_SHAPE_PROXYTYPE,
	mass = 1.0,
	restitution = 0.5
}

--set KINEMATIC flag for teapotRigidBody (required if you want to move the body manually)
teapotRigidBody:setCollisionFlags(bitor(teapotRigidBody:getCollisionFlags(), bullet.btCollisionObject.CF_KINEMATIC_OBJECT))
-- disable deactivation for body (we always want to check for collisions for the body)
teapotRigidBody:setActivationState(bullet.btCollisionObject.DISABLE_DEACTIVATION)
--add the object rigid bodies to the "bulletWorld"
bulletWorld:addRigidBody(teapotRigidBody)
--add osg objects to the VRJuggLua world (so we can see them)
RelativeTo.World:addChild(teapotOSG)

--add a frame action to set teapotRigidBody position to wand position
Actions.addFrameAction(function()
	while true do
		--create a new bullet transform object
		local teapotCurrentTransform = bullet.btTransform()
		--get the teapot's current transform
		teapotRigidBody:getMotionState():getWorldTransform(teapotCurrentTransform)
		--get the rotation compoent of the wand ("device") matrix
		local rotMatrixOfWand = device.matrix:getRotate()
		--create a bullet Quaternion by passing it rotation values from the wand
		local newRotation = bullet.btQuaternion(rotMatrixOfWand:x(),rotMatrixOfWand:y(),rotMatrixOfWand:z(),rotMatrixOfWand:w())
		--create a bullet vector of the wand's position
		local newOrigin = bullet.btVector3(device.position:x(), device.position:y(), device.position:z())
		--set location ("origin") of teapot to newOrigin
		teapotCurrentTransform:setOrigin(newOrigin)
		--set the rotation of the teapot to newRotation
		teapotCurrentTransform:setRotation(newRotation)
		--apply the updated transform to the teapotRigidBody
		teapotRigidBody:getMotionState():setWorldTransform(teapotCurrentTransform)
		--be sure to redraw the scene after each frame
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