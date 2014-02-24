/**
	@file
	@brief Implementation

	@date 2013

	@author
	Ryan Pavlik
	<rpavlik@iastate.edu> and <abiryan@ryand.net>
	http://academic.cleardefinition.com/
	Iowa State University Virtual Reality Applications Center
	Human-Computer Interaction Graduate Program
*/

//          Copyright Iowa State University 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


// Internal Includes
#include "ModuleEntryPoint.h"
#include "BindingFwd.h"
#include "ClassInfo.h"

#include "osgbCollision/CollisionShapes.h"

// Library/third-party includes
#include <luabind/open.hpp>

/// @todo maybe put this in a header file
luabind::scope getLuaBinding_osgbDynamicsRigidBody();

//Forward declare all the things we need
//Bullet:
//Linear Math
class btVector3;
class btTransform;
class btMotionState;
//BulletDynamics
class btSequentialImpulseConstraintSolver;
class btDiscreteDynamicsWorld;
class btDynamicsWorld;
class btConstraintSolver;
class btRigidBody;
//BulletCollision
class btAxisSweep3;
struct btBroadphaseProxy;
class btCollisionConfiguration;
class btBroadphaseInterface;
class btCollisionDispatcher;
class btDefaultCollisionConfiguration;
class btDispatcher;
class btCollisionShape;
class btBoxShape;
class btStaticPlaneShape;
class btSphereShape;
class btCompoundShape;
class btCollisionObject;
class btPolyhedralConvexShape;
class btConvexInternalShape;
class btConvexShape;
class btConcaveShape;
class btCollisionWorld;
//osgBullet:
namespace osgbDynamics{
    class MotionState;
    class PhysicsData;
    class PhysicsState;
    class PhysicsThread;
	class RigidBody;
}
namespace osgbCollision{
    class CollectVerticesVisitor;
    class ComputeCylinderVisitor;
    class ComputeShapeVisitor;
    class ComputeTriMeshVisitor;
}

// Standard includes
// - none


int luaopen_luabullet(lua_State *L) {
	using namespace luabind;
	open(L);
	//http://www.lua.org/manual/5.1/manual.html#5.3
	module(L, "bullet")
	[
        //bullet
		// Order matters - bases before derived!
	    getLuaBinding<btVector3>(),
		getLuaBinding<btMotionState>(),
		getLuaBinding<btCollisionObject>(),
	    getLuaBinding<btRigidBody>(),
		getLuaBinding<btConstraintSolver>(),
		getLuaBinding<btCollisionShape>(),
		getLuaBinding<btConvexShape>(),
		getLuaBinding<btConcaveShape>(),
		getLuaBinding<btConvexInternalShape>(),
		getLuaBinding<btPolyhedralConvexShape>(),
		getLuaBinding<btBoxShape>(),
		getLuaBinding<btStaticPlaneShape>(),
		getLuaBinding<btSphereShape>(),
	    getLuaBinding<btDefaultCollisionConfiguration>(),
		getLuaBinding<btDispatcher>(),
	    getLuaBinding<btCollisionDispatcher>(),
		getLuaBinding<btBroadphaseInterface>(),
	    getLuaBinding<btSequentialImpulseConstraintSolver>(),
	    getLuaBinding<btAxisSweep3>(),
		getLuaBinding<btCollisionWorld>(),
		getLuaBinding<btDynamicsWorld>(),
	    getLuaBinding<btDiscreteDynamicsWorld>(),
	    getLuaBinding<btTransform>(),
	    getLuaBinding<btBroadphaseProxy>(),
	    getLuaBinding<btCompoundShape>(),

	    scope() // trailing empty scope so we can put commas after each binding call
	];
	module(L, "osgbDynamics")
	[
        //osgBullet
	    getLuaBinding<osgbDynamics::MotionState>(),
	    getLuaBinding<osgbDynamics::PhysicsData>(),
	    getLuaBinding<osgbDynamics::PhysicsState>(),
	    getLuaBinding<osgbDynamics::PhysicsThread>(),
		getLuaBinding_osgbDynamicsRigidBody(),

	    scope() // trailing empty scope so we can put commas after each binding call
	];
    module(L, "osgbCollision")
	[
        //osgBullet
#if 0 // stuff we need to make introspection wrappers for instead
		getLuaBinding<osgbCollision::CollectVerticesVisitor>(),
        getLuaBinding<osgbCollision::ComputeCylinderVisitor>(),
	    getLuaBinding<osgbCollision::ComputeShapeVisitor>(),
	    getLuaBinding<osgbCollision::ComputeTriMeshVisitor>(),
#endif
	    btSphereCollisionShapeFromOSG(),
	    btBoxCollisionShapeFromOSG(),
	    btCylinderCollisionShapeFromOSG(),
	    btTriMeshCollisionShapeFromOSG(),
	    btConvexTriMeshCollisionShapeFromOSG(),
	    btConvexHullCollisionShapeFromOSG(),
	    btCompoundShapeFromOSGGeodes(),
	    btCompoundShapeFromOSGGeometry(),
	    btCompoundShapeFromBounds(),

	    scope() // trailing empty scope so we can put commas after each binding call
	];
	bindClassInfo(L);
	return 0;
}
