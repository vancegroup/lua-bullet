-- lua-bullet Dice example, ported from osgBullet example (dice.cpp)
require("luabullet")
require("osgDB")
require "AddAppDirectory"
AddAppDirectory()

runfile[[simpleLights.lua]]

local function makeDie(bw, pos)
	local node = Model("../assets/dice.ive")
	local root = MatrixTransform{
		Transform{
			position = pos,
			node
		}
	}
	local cs = osgbCollision.btBoxCollisionShapeFromOSG(node)
	-- this differs slightly from the C++ (see RigidBody.cpp for details on what can be passed in)
	local body = osgbDynamics.createRigidBody{
		collisionShape = cs,
		sceneGraph = root,
		shapeType = bullet.btBroadphaseProxy.BOX_SHAPE_PROXYTYPE,
		mass = 1.0,
		restitution = 1.0
	}
	bw:addRigidBody(body)
	return root
end
-- bitwise inclusive OR (http://ricilake.blogspot.com/2007/10/iterating-bits-in-lua.html)
local function bitor(x, y)
	local function bit(p)
	  return 2 ^ (p - 1)  -- 1-based indexing
	end

	local function hasbit(x, p)
	  return x % (p + p) >= p
	end

	local function setbit(x, p)
	  return hasbit(x, p) and x or x + p
	end

	local function clearbit(x, p)
	  return hasbit(x, p) and x - p or x
	end
	
	local p = 1; 
	local z = 0; 
	local limit = x > y and x or y
	while p <= limit do
		if hasbit(x, p) or hasbit(y, p) then
			z = z + p
		end
		p = p + p
	end
	return z
end

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

local function osgBox(center, halfLengths)
	local l = osg.Vec3d(halfLengths:x()*2, halfLengths:y()*2, halfLengths:z()*2)
	box = osg.Box(osg.Vec3f(center:x(),center:y(),center:z()), l:x(), l:y(), l:z())
	shape = osg.ShapeDrawable(box)
	geode = osg.Geode()
	geode:addDrawable(shape)
	local t = Transform{
		geode,
	}
	t:setScale(l)
	return t
end

--create a "bulletWorld" main object to handle bullet physics
local bulletWorld = initPhysics()
--create two simple osgObjects that get added to our bulletWorld
local die1 = makeDie(bulletWorld, {1.75, 5, -4})
local die2 = makeDie(bulletWorld, {0, 2, -4})
--add osgObjects to osgGroup node
local root = Group{
	die1,
	die2
}
--create a floor osgObject
local floorTransform = osg.MatrixTransform()
--create a static plane (ground object) for dice objects to land upon
cs = bullet.btStaticPlaneShape(bullet.btVector3(0, 1, 0), 0)
--Create floor OSG to visualize the static plane: osgBox(position, halfLengths)
local thefloorOSG = osgBox(Vec(0, .025, -2), Vec(2, .025, 2))
--add floorOSG object to floor MT transform
floorTransform:addChild(thefloorOSG)
--create motionstate for constructing static plane rigid body
motionState = osgbDynamics.MotionState()
--associate osgMT transform with motionState
motionState:setTransform(floorTransform)

--create rigidBodyConstructorInfo object (required to create rigid body):
--use: bullet.btRigidBody.btRigidBodyConstructionInfo(mass, motionState, collisionShape, inertia)
rigidBodyConstructorInfo = bullet.btRigidBody.btRigidBodyConstructionInfo(0.0, motionState, cs, bullet.btVector3(0.0, 0.0, 0.0))
--create rigid body for the floor
floorRigidBody = bullet.btRigidBody(rigidBodyConstructorInfo)
--set flags for floor rigid body
floorRigidBody:setCollisionFlags(bitor(floorRigidBody:getCollisionFlags(), bullet.btCollisionObject.CF_KINEMATIC_OBJECT))
floorRigidBody:setActivationState(bullet.btCollisionObject.DISABLE_DEACTIVATION)
--add floor rigid body to bulletWorld
bulletWorld:addRigidBody(floorRigidBody)
--add floor (osg) MT transform to the root group node
root:addChild(floorTransform)
--add root group node to scenegraph
RelativeTo.World:addChild(root)

--http://stackoverflow.com/questions/12778229/stepsimulation-bullet-physics
--http://bulletphysics.org/mediawiki-1.5.8/index.php/Stepping_The_World

--add a frame action to step the simulation based on dt
Actions.addFrameAction(function()
	-- wait 3 seconds before starting simulation
	Actions.waitSeconds(3)
	while true do
		elapsed = Actions.waitForRedraw()
		-- step simulation one step
		bulletWorld:stepSimulation(elapsed)
	end
end)
