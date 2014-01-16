-- lua-bullet Dice example, ported from osgBullet example (dice.cpp)
require("luabullet")
require("osgDB")
-- require("osgbCollision")
-- require("osgbDynamics")

require "AddAppDirectory"
AddAppDirectory()

function makeDie(bw)
	local root = osg.MatrixTransform()
	-- load in dice.osg model
	node = Model "dice.osg"
	
	root:addChild(node)
	
	cs = osgbCollision.btBoxCollisionShapeFromOSG(node)
	
	cr = osgbDynamics.CreationRecord()
	
	cr.sceneGraph = root
	cr.shapeType = bullet.btBroadphaseProxy.BOX_SHAPE_PROXYTYPE
	cr.mass = 1.0
	cr.restitution = 1.0
	
	body = osgbDynamics.createRigidBody(cr, cs)
	
	bw:addRigidBody(body)
	
	return root
end


function initPhysics()
	print("initPhysics")
	 constructionInfo = bullet.btDefaultCollisionConstructionInfo()
	print("a")
	 collisionConfiguration = bullet.btDefaultCollisionConfiguration(constructionInfo)
	print("b")
	 dispatcher = bullet.btCollisionDispatcher(collisionConfiguration)
	print("c")
	 solver = bullet.btSequentialImpulseConstraintSolver()
	print("d")
	
	 worldAabbMin = bullet.btVector3(-10000, -10000, -10000)
	 worldAabbMax = bullet.btVector3(10000, 10000, 10000)
	print("e")
	
	 inter = bullet.btAxisSweep3(worldAabbMin, worldAabbMax, 1000)
	print("f")
	dynamicsWorld = bullet.btDiscreteDynamicsWorld(dispatcher, inter, solver, collisionConfiguration)
	print("g")
	dynamicsWorld:setGravity(bullet.btVector3(0, 0, 9.8))
	
	print("end init function")
	return dynamicsWorld
end


function osgBox(center, halfLengths)
	local l = osg.Vec3(halfLengths * 2.0)
	box = osg.Box(center, l.x(), l.y(), l.z())
	shape = osg.ShapeDrawable(box)
	geode = osg.Geode()
	geode:addDrawable(shape)
	return geode
end

print(" here")
local bulletWorld = initPhysics()

local root = osg.Group()

die1 = makeDie(bulletWorld)
die2 = makeDie(bulletWorld)

root:addChild(die1)
root:addChild(die1)

local xDim = 10.0
local yDim = 10.0
local zDim = 10.0
local thick = 0.1

local shakeBox = osg.MatrixTransform()

local cs = bullet.btCompoundShape()

-- // floor -Z (far back of the shake cube)
do
	halfLengths = osg.Vec3(xDim*.5, yDim*.5, thick*.5)
	center = osg.Vec3(0, 0,  zDim*.5)
	tbox = osgBox( center, halfLengths )
	shakebox:addChild(tbox)
	box = bullet.btBoxShape(osgbCollision.asBtVector2(halfLengths))
	trans = bullet.btTransform()
	trans:setIdentity()
	trans:setOrigin(osgbCollision.asBtVector2(center))
	cs:addChildShape(trans,box)
end
-- // top +Z (invisible, to allow user to see through; no OSG analogue
do
	halfLengths = osg.Vec3(xDim*.5, yDim*.5, thick*.5)
	center = osg.Vec3(0, 0,  -zDim*.5)
	tbox = osgBox( center, halfLengths )
	-- shakebox:addChild(tbox)
	box = bullet.btBoxShape(osgbCollision.asBtVector2(halfLengths))
	trans = bullet.btTransform()
	trans:setIdentity()
	trans:setOrigin(osgbCollision.asBtVector2(center))
	cs:addChildShape(trans,box)
end
-- // left -X  
do
	halfLengths = osg.Vec3(thick*.5, yDim*.5, zDim*.5)
	center = osg.Vec3(-xDim*.5, 0.0, 0.0 )
	tbox = osgBox( center, halfLengths )
	shakebox:addChild(tbox)
	box = bullet.btBoxShape(osgbCollision.asBtVector2(halfLengths))
	trans = bullet.btTransform()
	trans:setIdentity()
	trans:setOrigin(osgbCollision.asBtVector2(center))
	cs:addChildShape(trans,box)
end
-- // right +X
do
	halfLengths = osg.Vec3(thick*.5, yDim*.5, zDim*.5)
	center = osg.Vec3(xDim*.5, 0.0, 0.0 )
	tbox = osgBox( center, halfLengths )
	shakebox:addChild(tbox)
	box = bullet.btBoxShape(osgbCollision.asBtVector2(halfLengths))
	trans = bullet.btTransform()
	trans:setIdentity()
	trans:setOrigin(osgbCollision.asBtVector2(center))
	cs:addChildShape(trans,box)
end
-- // bottom of window -Y
do
	halfLengths = osg.Vec3( xDim*.5, thick*.5, zDim*.5 )
	center = osg.Vec3( 0.0, -yDim*.5, 0.0 )
	tbox = osgBox( center, halfLengths )
	shakebox:addChild(tbox)
	box = bullet.btBoxShape(osgbCollision.asBtVector2(halfLengths))
	trans = bullet.btTransform()
	trans:setIdentity()
	trans:setOrigin(osgbCollision.asBtVector2(center))
	cs:addChildShape(trans,box)
end
-- // bottom of window -Y
do
	halfLengths = osg.Vec3( xDim*.5, thick*.5, zDim*.5)
	center = osg.Vec3( 0.0, yDim*.5, 0.0 )
	tbox = osgBox( center, halfLengths )
	shakebox:addChild(tbox)
	box = bullet.btBoxShape(osgbCollision.asBtVector2(halfLengths))
	trans = bullet.btTransform()
	trans:setIdentity()
	trans:setOrigin(osgbCollision.asBtVector2(center))
	cs:addChildShape(trans,box)
end
-- /* END: Create environment boxes */
shakeMotion = osgbDynamics.MotionState()
shakeMotion:setTransform( shakeBox )
local mass = bullet.btScalar(0.0)
local inertia = bullet.btVector3(0.0,0.0,0.0)
--bullet.?
rb = btRigidBody.btRigidBodyConstructionInfo( mass, shakeMotion, cs, inertia )
shakeBody = bullet.btRigidBody(rb)
-- shakeBody->setCollisionFlags( shakeBody->getCollisionFlags() | btCollisionObject::CF_KINEMATIC_OBJECT );
shakeBody:setCollisionFlags( shakeBody:getCollisionFlags() + btCollisionObject.CF_KINEMATIC_OBJECT )
shakeBody:setActivationState( DISABLE_DEACTIVATION )
bulletWorld:addRigidBody( shakeBody )

root:addChild( shakeBox )

    -- double prevSimTime = 0.;
    -- while( !viewer.done() )
    -- {
        -- const double currSimTime = viewer.getFrameStamp()->getSimulationTime();
        -- double elapsed( currSimTime - prevSimTime );
        -- if( viewer.getFrameStamp()->getFrameNumber() < 3 )
            -- elapsed = 1./60.;
        -- //osg::notify( osg::ALWAYS ) << elapsed / 3. << ", " << 1./180. << std::endl;
        -- bulletWorld->stepSimulation( elapsed, 4, elapsed/4. );
        -- prevSimTime = currSimTime;
        -- viewer.frame();
    -- }
