/**
	@file
	@brief Implementation

	@date 2013

	@author
	Patrick Carlson
	<carlsonp@iastate.edu>
	Iowa State University Virtual Reality Applications Center
	Human-Computer Interaction Graduate Program
*/

//          Copyright Iowa State University 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


// Internal Includes
#include "../../BindingFwd.h"

// Library/third-party includes
#include <luabind/class.hpp>

#include <BulletDynamics/Dynamics/btRigidBody.h>
#include <BulletCollision/CollisionShapes/btCollisionShape.h>
#include <BulletDynamics/ConstraintSolver/btTypedConstraint.h>
#include <LinearMath/btSerializer.h>

// Standard includes
// - none

namespace {
    const btCollisionShape* getCollisionShapeConst(btRigidBody const * b) {
        return b->getCollisionShape();
    }
    btCollisionShape* getCollisionShapeNonConst(btRigidBody * b) {
        return b->getCollisionShape();
    }

    const btBroadphaseProxy* getBroadphaseProxyConst(btRigidBody const * b) {
        return b->getBroadphaseProxy();
    }
    btBroadphaseProxy* getBroadphaseProxyNonConst(btRigidBody * b) {
        return b->getBroadphaseProxy();
    }

    const btMotionState* getMotionStateConst(btRigidBody const * b) {
        return b->getMotionState();
    }
    btMotionState* getMotionStateNonConst(btRigidBody * b) {
        return b->getMotionState();
    }
}

template<> luabind::scope getLuaBinding<btRigidBody>() {
	using namespace luabind;

	return
	    class_<btRigidBody> ("btRigidBody")
	    .def(constructor<btRigidBody::btRigidBodyConstructionInfo>())
	    .def(constructor<btScalar, btMotionState *, btCollisionShape *, const btVector3 &>())
	    ///@TODO: figure out how to bind this struct appropriately
	    /*.scope
        [
            class_<btRigidBodyConstructionInfo>("btRigidBodyConstructionInfo"),
            def(constructor<btScalar, btMotionState*, btCollisionState*, const btVector3&>())
        ];*/
	    .def("proceedToTransform", &btRigidBody::proceedToTransform)
	    .def("predictIntegratedTransform", &btRigidBody::predictIntegratedTransform)
	    .def("saveKinematicsState", &btRigidBody::saveKinematicState)
	    .def("applyGravity", &btRigidBody::applyGravity)
	    .def("setGravity", &btRigidBody::setGravity)
	    .def("getGravity", &btRigidBody::getGravity)
	    .def("setDamping", &btRigidBody::setDamping)
	    .def("getLinearDamping", &btRigidBody::getLinearDamping)
	    .def("getAngularDamping", &btRigidBody::getAngularDamping)
	    .def("getLinearSleepingThreshold", &btRigidBody::getLinearSleepingThreshold)
	    .def("getAngularSleepingThreshold", &btRigidBody::getAngularSleepingThreshold)
	    .def("applyDamping", &btRigidBody::applyDamping)
	    .def("getCollisionShape", &getCollisionShapeConst)
	    .def("getCollisionShape", &getCollisionShapeNonConst)
	    .def("setMassProps", &btRigidBody::setMassProps)
	    .def("getLinearFactor", &btRigidBody::getLinearFactor)
	    .def("setLinearFactor", &btRigidBody::setLinearFactor)
	    .def("getInvMass", &btRigidBody::getInvMass)
	    .def("getInvInertiaTensorWorld", &btRigidBody::getInvInertiaTensorWorld)
	    .def("integrateVelocities", &btRigidBody::integrateVelocities)
	    .def("setCenterOfMassTransform", &btRigidBody::setCenterOfMassTransform)
	    .def("applyCentralForce", &btRigidBody::applyCentralForce)
	    .def("getTotalForce", &btRigidBody::getTotalForce)
	    .def("getTotalTorque", &btRigidBody::getTotalTorque)
	    .def("getInvInertiaDiagLocal", &btRigidBody::getInvInertiaDiagLocal)
	    .def("setInvInertiaDiagLocal", &btRigidBody::setInvInertiaDiagLocal)
	    .def("setSleepingThresholds", &btRigidBody::setSleepingThresholds)
	    .def("applyTorque", &btRigidBody::applyTorque)
	    .def("applyForce", &btRigidBody::applyForce)
	    .def("applyCentralImpulse", &btRigidBody::applyCentralForce)
	    .def("applyTorqueImpulse", &btRigidBody::applyTorqueImpulse)
	    .def("applyImpulse", &btRigidBody::applyImpulse)
	    .def("clearForces", &btRigidBody::clearForces)
	    .def("updateInertiaTensor", &btRigidBody::updateInertiaTensor)
	    .def("getCenterOfMassPosition", &btRigidBody::getCenterOfMassPosition)
	    .def("getOrientation", &btRigidBody::getOrientation)
	    .def("getCenterOfMassPosition", &btRigidBody::getCenterOfMassPosition)
	    .def("getOrientation", &btRigidBody::getOrientation)
	    .def("getCenterOfMassTransform", &btRigidBody::getCenterOfMassTransform)
	    .def("getLinearVelocity", &btRigidBody::getLinearVelocity)
	    .def("getAngularVelocity", &btRigidBody::getAngularVelocity)
	    .def("setLinearVelocity", &btRigidBody::setLinearVelocity)
	    .def("setAngularVelocity", &btRigidBody::setAngularVelocity)
	    .def("getVelocityInLocalPoint", &btRigidBody::getVelocityInLocalPoint)
	    .def("translate", &btRigidBody::translate)
	    .def("getAabb", &btRigidBody::getAabb)
	    .def("computeImpulseDenominator", &btRigidBody::computeImpulseDenominator)
	    .def("computeAngularImpulseDenominator", &btRigidBody::computeAngularImpulseDenominator)
	    .def("updateDeactivation", &btRigidBody::updateDeactivation)
	    .def("wantsSleeping", &btRigidBody::wantsSleeping)
	    .def("getBroadphaseProxy", &getBroadphaseProxyConst)
	    .def("getBroadphaseProxy", &getBroadphaseProxyNonConst)
	    .def("setNewBroadphaseProxy", &btRigidBody::setNewBroadphaseProxy)
	    .def("getMotionState", &getMotionStateConst)
	    .def("getMotionState", &getMotionStateNonConst)
	    .def("setMotionState", &btRigidBody::setMotionState)
	    //http://www.rasterbar.com/products/luabind/docs.html#overloaded-functions
	    .def("setAngularFactor", (void(btRigidBody::*)(btScalar)) &btRigidBody::setAngularFactor)
	    .def("setAngularFactor", (void(btRigidBody::*)(const btVector3&)) &btRigidBody::setAngularFactor)
	    .def("getAngularFactor", &btRigidBody::getAngularFactor)
	    .def("isInWorld", &btRigidBody::isInWorld)
	    .def("checkCollideWithOverride", &btRigidBody::checkCollideWithOverride)
	    .def("addConstraintRef", &btRigidBody::addConstraintRef)
	    .def("removeConstraintRef", &btRigidBody::removeConstraintRef)
	    .def("getConstraintRef", &btRigidBody::getConstraintRef)
	    .def("getNumConstraintRefs", &btRigidBody::getNumConstraintRefs)
	    .def("setFlags", &btRigidBody::setFlags)
	    .def("getFlags", &btRigidBody::getFlags)
	    .def("computeGyroscopicForce", &btRigidBody::computeGyroscopicForce)
	    .def("calculateSerializeBufferSize", &btRigidBody::calculateSerializeBufferSize)
	    .def("serialize", &btRigidBody::serialize)
	    .def("serializeSingleObject", &btRigidBody::serializeSingleObject)
	    ;
}
