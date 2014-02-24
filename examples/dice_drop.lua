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

local bulletWorld = initPhysics()

local die1 = makeDie(bulletWorld, {1.75, 5, -4})
local die2 = makeDie(bulletWorld, {0, 2, -4})

local root = Group{
	die1,
	die2
}

local shakebox = osg.MatrixTransform()

cs = bullet.btStaticPlaneShape(bullet.btVector3(0, 1, 0), 0)
local halfLengths = Vec(2, .025, 2)
local center = Vec(0, .025, -2)
local thefloor = osgBox(center, halfLengths)
shakebox:addChild(thefloor)

shakeMotion = osgbDynamics.MotionState()
shakeMotion:setTransform(shakebox)
local mass = 0.0
local inertia = bullet.btVector3(0.0, 0.0, 0.0)

rb = bullet.btRigidBody.btRigidBodyConstructionInfo(mass, shakeMotion, cs, inertia)
shakeBody = bullet.btRigidBody(rb)

shakeBody:setCollisionFlags(bitor(shakeBody:getCollisionFlags(), bullet.btCollisionObject.CF_KINEMATIC_OBJECT))
shakeBody:setActivationState(bullet.btCollisionObject.DISABLE_DEACTIVATION)
bulletWorld:addRigidBody(shakeBody)

root:addChild(shakebox)

RelativeTo.World:addChild(root)

--http://stackoverflow.com/questions/12778229/stepsimulation-bullet-physics
--http://bulletphysics.org/mediawiki-1.5.8/index.php/Stepping_The_World
function startSim()
	Actions.addFrameAction(function()
		Actions.waitSeconds(3)
		while true do
			elapsed = Actions.waitForRedraw()
			bulletWorld:stepSimulation(elapsed)
		end
	end)
end
startSim()