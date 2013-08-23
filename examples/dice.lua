-- lua-bullet Dice example, ported from osgBullet example (dice.cpp)


function makeDie(bw)
	local root = osg.MatrixTransform()
	-- load in dice.osg model
	-- TODO: should this be done using the Model() method from VRJugglua?
	local node = osg...assets/dice.osg
	
	root.addChild(node)
	
	local cs = osgbCollision.btBoxCollisionShapeFromOSG(node)
	
	local cr = osgbDynamics.CreationRecord()
	
	cr.sceneGraph = root
	cr.shapeType = BOX_SHAPE_PROXYTYPE -- TODO: does this need to be bound?
	cr.mass = 1
	cr.restitution = 1
	
	local body = osgbDynamics.createRigidBody(cr, cs)
	
	bw:addRigidBody(body)
	
	return root
end


function initPhysics()
	local constructionInfo = bullet.btDefaultCollisionConfiguration.btDefaultCollisionConstructionInfo()
	local collisionConfiguration = bullet.btDefaultCollisionConfiguration(constructionInfo)
	local dispatcher = bullet.btCollisionDispatcher(collisionConfiguration)
	local solver = bullet.btSequentialImpulseConstraintSolver()
	
	local worldAabbMin = bullet.btVector3(-10000, -10000, -10000)
	local worldAabbMax = bullet.btVector3(10000, 10000, 10000)
	
	local inter = bullet.btAxisSweep3(worldAabbMin, worldAabbMax, 1000)
	
	local dynamicsWorld = bullet.btDiscreteDynamicsWorld(dispatcher, inter, solver, collisionConfiguration)
	
	local dynamicisWorld:setGravity(bullet.btVector3(0, 0, 9.8))
	
	return dynamicsWorld
end


function osgBox(center, halfLengths)
	local l = osg.Vec3(halfLengths * 2.0)
	box = osg.Box(center, l.x(), l.y(), l.z())
	shape = osg.ShapeDrawable(box)
	geode = osg.Geode()
	geode.addDrawable(shape)
	return geode
end


local bulletWorld = initPhysics()

local root = osg.Group()

root.addChild(makeDie(bulletWorld))
root.addChild(makeDie(bulletWOrld))

local xDim = 10.0
local yDim = 10.0
local zDim = 10.0
local thick = 0.1

local shakeBox = osg.MatrixTransform()

local cs = bullet.btCompoundShape()


