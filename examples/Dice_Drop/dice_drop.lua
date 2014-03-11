require("luabullet")
require "AddAppDirectory"
AddAppDirectory()
runfile[[../simpleLights.lua]]

local function initPhysics()
	constructionInfo = bullet.btDefaultCollisionConstructionInfo()
	collisionConfiguration = bullet.btDefaultCollisionConfiguration(constructionInfo)
	dispatcher = bullet.btCollisionDispatcher(collisionConfiguration)
	solver = bullet.btSequentialImpulseConstraintSolver()
	worldAabbMin = bullet.btVector3(-10000, -10000, -10000)
	worldAabbMax = bullet.btVector3(10000, 10000, 10000)
	inter = bullet.btAxisSweep3(worldAabbMin, worldAabbMax, 1000)
	dynamicsWorld = bullet.btDiscreteDynamicsWorld(dispatcher, inter, solver, collisionConfiguration)
	dynamicsWorld:setGravity(bullet.btVector3(0, -9.8, 0))
	return dynamicsWorld
end

local function makeDie(bw, pos)
	--create OSG geometry
	local die = MatrixTransform{
		Transform{
			position = pos,
			Model("../../assets/dice.ive")
		}
	}
	--create bullet rigid body
	local dieRigidBody = osgbDynamics.createRigidBody{
		-- by default, shapeType is a box if not specified
		sceneGraph = die,
		mass = 1.0,
		restitution = 1.0
	}
	bw:addRigidBody(dieRigidBody)
	return die
end

--create a "bulletWorld" main object to handle bullet physics & objects
local bulletWorld = initPhysics()
--create two simple osgObjects that get added to our bulletWorld (dice)
local die1 = makeDie(bulletWorld, {1.75, 5, -4})
local die2 = makeDie(bulletWorld, {0, 2, -4})
--add osgObjects to osgGroup node
local root = Group{
	die1,
	die2
}

function createFloorOSGandStaticPlane()
	local floorTransform = osg.MatrixTransform()
	--create a static plane (ground object) for dice objects to land upon - set for pos Y direction
	cs = bullet.btStaticPlaneShape(bullet.btVector3(0, 1, 0), 0)
	--Create floor OSG to visualize the static plane: osgBox(position, halfLengths)
	local thefloorOSG = Model[[../../assets/floor.ive]]
	--add floorOSG object to floor MT transform
	floorTransform:addChild(thefloorOSG)
	--create motionstate for constructing static plane rigid body
	motionState = osgbDynamics.MotionState()
	--associate floorTransform with motionState
	motionState:setTransform(floorTransform)
	--create: bullet.btRigidBody.btRigidBodyConstructionInfo(mass, motionState, collisionShape, inertia)
	rigidBodyConstructorInfo = bullet.btRigidBody.btRigidBodyConstructionInfo(0.0, motionState, cs, bullet.btVector3(0.0, 0.0, 0.0))
	--create rigid body for the floor using rigidBodyConstructorInfo
	floorRigidBody = bullet.btRigidBody(rigidBodyConstructorInfo)
	--add floor rigid body to bulletWorld
	bulletWorld:addRigidBody(floorRigidBody)
	--add floor (osg) MT transform to the root group node
	root:addChild(floorTransform)
end


createFloorOSGandStaticPlane()
--add root group node to scenegraph
RelativeTo.World:addChild(root)

--add a frame action to step the simulation based on dt
Actions.addFrameAction(function()
		-- wait 3 seconds before starting simulation
		Actions.waitSeconds(3)
		while true do
			elapsed = Actions.waitForRedraw()
			bulletWorld:stepSimulation(elapsed)
		end
	end)