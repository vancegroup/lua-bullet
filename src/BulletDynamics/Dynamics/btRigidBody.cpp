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

// Standard includes
// - none

namespace {
    const btCollisionShape* getCollisionShapeConst(btRigidBody const * b) {
        return b->getCollisionShape();
    }
    btCollisionShape* getCollisionShapeNonConst(btRigidBody * b) {
        return b->getCollisionShape();
    }
}

template<> luabind::scope getLuaBinding<btRigidBody>() {
	using namespace luabind;

	return
	    class_<btRigidBody> ("btRigidBody")
	    .def(constructor<const btRigidBody::btRigidBodyConstructionInfo &>())
	    .def(constructor<btScalar, btMotionState *, btCollisionShape *, const btVector3 &>())
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
	    //.def("getCollisionShape", &getCollisionShapeConst)
	    //.def("getCollisionShape", &getCollisionShapeNonConst)
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
	    //.def("getBroadphaseProxy", (btBroadphaseProxy const * (btRigidBody::*)() const)&btRigidBody::getBroadphaseProxy)
	    //.def("setNewBroadphaseProxy", &btRigidBody::setNewBroadphaseProxy)
	    //.def("getMotionState", &btRigidBody::getMotionState)
	    //.def("setMotionState", &btRigidBody::setMotionState)
	    //.def("setAngularFactor", &btRigidBody::setAngularFactor)
	    //.def("getAngularFactor", &btRigidBody::getAngularFactor)
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
	    //.def("serialize", &btRigidBody::serialize)
	    //.def("serializeSingleObject", &btRigidBody::serializeSingleObject)
	    ;
}
