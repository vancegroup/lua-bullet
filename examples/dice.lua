-- lua-bullet Dice example, ported from osgBullet example (dice.cpp)
require("luabullet")
require("osgDB")

require "AddAppDirectory"
AddAppDirectory()
runfile[[simpleLights.lua]]

function makeDie(bw, pos)
	-- load in dice.osg model
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

function bit(p)
  return 2 ^ (p - 1)  -- 1-based indexing
end

function hasbit(x, p)
  return x % (p + p) >= p
end

function setbit(x, p)
  return hasbit(x, p) and x or x + p
end

function clearbit(x, p)
  return hasbit(x, p) and x - p or x
end

-- bitwise inclusive OR
-- http://ricilake.blogspot.com/2007/10/iterating-bits-in-lua.html
-- online calculator
-- http://www.miniwebtool.com/bitwise-calculator/
function bitor(x, y)
  local p = 1; local z = 0; local limit = x > y and x or y
  while p <= limit do
    if hasbit(x, p) or hasbit(y, p) then
      z = z + p
    end
    p = p + p
  end
  return z
end


function initPhysics()
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


function osgBox(center, halfLengths)
	local l = osg.Vec3f(halfLengths:x() * 2.0, halfLengths:y() * 2.0, halfLengths:z() * 2.0)
	box = osg.Box(osg.Vec3f(center:x(),center:y(),center:z()), l:x(), l:y(), l:z())
	shape = osg.ShapeDrawable(box)
	geode = osg.Geode()
	geode:addDrawable(shape)
	return geode
end


bulletWorld = initPhysics()

die1 = makeDie(bulletWorld, {0, 2, -3})
die2 = makeDie(bulletWorld, {0, 0, -3})

local root = Group{
	die1,
	die2
}



local xDim = 10.0
local yDim = 10.0
local zDim = 10.0
local thick = 0.1

local shakebox = osg.MatrixTransform()

cs = bullet.btCompoundShape()


-- // floor -Z (far back of the shake cube)
do
	halfLengths = Vec(xDim*.5, yDim*.5, thick*.5)
	center = Vec(0, 0,  zDim*.5)
	tbox = osgBox( center, halfLengths )
	shakebox:addChild(tbox)
	box = bullet.btBoxShape(bullet.btVector3(halfLengths:x(), halfLengths:y(), halfLengths:z()))
	trans = bullet.btTransform()
	trans:setIdentity()
	trans:setOrigin(bullet.btVector3(center:x(), center:y(), center:z()))
	cs:addChildShape(trans, box)
end
-- // top +Z (invisible, to allow user to see through; no OSG analogue
do
	halfLengths = osg.Vec3(xDim*.5, yDim*.5, thick*.5)
	center = osg.Vec3(0, 0,  -zDim*.5)
	tbox = osgBox( center, halfLengths )
	-- shakebox:addChild(tbox) --no top to box
	box = bullet.btBoxShape(bullet.btVector3(halfLengths:x(), halfLengths:y(), halfLengths:z()))
	trans = bullet.btTransform()
	trans:setIdentity()
	trans:setOrigin(bullet.btVector3(center:x(), center:y(), center:z()))
	cs:addChildShape(trans, box)
end
-- // left -X  
do
	halfLengths = osg.Vec3(thick*.5, yDim*.5, zDim*.5)
	center = osg.Vec3(-xDim*.5, 0.0, 0.0 )
	tbox = osgBox( center, halfLengths )
	shakebox:addChild(tbox)
	box = bullet.btBoxShape(bullet.btVector3(halfLengths:x(), halfLengths:y(), halfLengths:z()))
	trans = bullet.btTransform()
	trans:setIdentity()
	trans:setOrigin(bullet.btVector3(center:x(), center:y(), center:z()))
	cs:addChildShape(trans, box)
end
-- // right +X
do
	halfLengths = osg.Vec3(thick*.5, yDim*.5, zDim*.5)
	center = osg.Vec3(xDim*.5, 0.0, 0.0 )
	tbox = osgBox( center, halfLengths )
	shakebox:addChild(tbox)
	box = bullet.btBoxShape(bullet.btVector3(halfLengths:x(), halfLengths:y(), halfLengths:z()))
	trans = bullet.btTransform()
	trans:setIdentity()
	trans:setOrigin(bullet.btVector3(center:x(), center:y(), center:z()))
	cs:addChildShape(trans, box)
end
-- // bottom of window -Y
do
	halfLengths = osg.Vec3( xDim*.5, thick*.5, zDim*.5 )
	center = osg.Vec3( 0.0, -yDim*.5, 0.0 )
	tbox = osgBox( center, halfLengths )
	shakebox:addChild(tbox)
	box = bullet.btBoxShape(bullet.btVector3(halfLengths:x(), halfLengths:y(), halfLengths:z()))
	trans = bullet.btTransform()
	trans:setIdentity()
	trans:setOrigin(bullet.btVector3(center:x(), center:y(), center:z()))
	cs:addChildShape(trans, box)
end
-- // bottom of window -Y
do
	halfLengths = osg.Vec3( xDim*.5, thick*.5, zDim*.5)
	center = osg.Vec3( 0.0, yDim*.5, 0.0 )
	tbox = osgBox( center, halfLengths )
	shakebox:addChild(tbox)
	box = bullet.btBoxShape(bullet.btVector3(halfLengths:x(), halfLengths:y(), halfLengths:z()))
	trans = bullet.btTransform()
	trans:setIdentity()
	trans:setOrigin(bullet.btVector3(center:x(), center:y(), center:z()))
	cs:addChildShape(trans, box)
end
-- /* END: Create environment boxes */

shakeMotion = osgbDynamics.MotionState()
shakeMotion:setTransform( shakebox )
local mass = 0.0 --in C++, this was of type btScalar
local inertia = bullet.btVector3(0.0, 0.0, 0.0)

rb = bullet.btRigidBody.btRigidBodyConstructionInfo( mass, shakeMotion, cs, inertia )
shakeBody = bullet.btRigidBody(rb)

-- Original C++
-- shakeBody->setCollisionFlags( shakeBody->getCollisionFlags() | btCollisionObject::CF_KINEMATIC_OBJECT );
print (bitor(shakeBody:getCollisionFlags(), bullet.btCollisionObject.CF_KINEMATIC_OBJECT))
shakeBody:setCollisionFlags( bitor(shakeBody:getCollisionFlags(), bullet.btCollisionObject.CF_KINEMATIC_OBJECT) )
shakeBody:setActivationState( bullet.btCollisionObject.DISABLE_DEACTIVATION )
bulletWorld:addRigidBody( shakeBody )

--root:addChild( shakebox )

RelativeTo.World:addChild(root)


Actions.addFrameAction(function()
	while true do
		elapsed = Actions.waitForRedraw()
		--http://stackoverflow.com/questions/12778229/stepsimulation-bullet-physics
		--http://bulletphysics.org/mediawiki-1.5.8/index.php/Stepping_The_World
		bulletWorld:stepSimulation(elapsed)
	end
end)
