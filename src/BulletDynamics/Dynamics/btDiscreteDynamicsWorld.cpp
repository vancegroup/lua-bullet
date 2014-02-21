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

#include <BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h>
#include <BulletDynamics/ConstraintSolver/btConstraintSolver.h>
#include <BulletCollision/CollisionDispatch/btCollisionConfiguration.h>
#include <BulletDynamics/Dynamics/btRigidBody.h>
#include <BulletDynamics/ConstraintSolver/btTypedConstraint.h>
#include <BulletDynamics/Dynamics/btActionInterface.h>
#include <LinearMath/btSerializer.h>
#include <BulletCollision/CollisionDispatch/btSimulationIslandManager.h>

// Standard includes
// - none


namespace {
    const btSimulationIslandManager* getSimulationIslandManagerConst(btDiscreteDynamicsWorld const * b) {
        return b->getSimulationIslandManager();
    }
    btSimulationIslandManager* getSimulationIslandManagerNonConst(btDiscreteDynamicsWorld * b) {
        return b->getSimulationIslandManager();
    }

    const btTypedConstraint* getConstraintConst(btDiscreteDynamicsWorld const * b, int index) {
        return b->getConstraint(index);
    }
    btTypedConstraint* getConstraintNonConst(btDiscreteDynamicsWorld * b, int index) {
        return b->getConstraint(index);
    }
}
static int stepSimulationSimple(btDiscreteDynamicsWorld & self, btScalar timeStep) {
	return self.stepSimulation(timeStep);
}

template<> luabind::scope getLuaBinding<btDiscreteDynamicsWorld>() {
	using namespace luabind;

	return
	    class_<btDiscreteDynamicsWorld, btDynamicsWorld> ("btDiscreteDynamicsWorld")
			.def(constructor<btDispatcher *, btBroadphaseInterface *, btConstraintSolver *, btCollisionConfiguration *>())
			.def("stepSimulation", &btDiscreteDynamicsWorld::stepSimulation)
			.def("stepSimulation", &stepSimulationSimple)
			.def("synchronizeMotionStates", &btDiscreteDynamicsWorld::synchronizeMotionStates)
			.def("synchronizeSingleMotionState", &btDiscreteDynamicsWorld::synchronizeSingleMotionState)
			.def("addConstraint", &btDiscreteDynamicsWorld::addConstraint)
			.def("removeConstraint", &btDiscreteDynamicsWorld::removeConstraint)
			.def("addAction", &btDiscreteDynamicsWorld::addAction)
			.def("removeAction", &btDiscreteDynamicsWorld::removeAction)
			.def("getSimulationIslandManager", &getSimulationIslandManagerConst)
			.def("getSimulationIslandManager", &getSimulationIslandManagerNonConst)
			.def("getCollisionWorld", &btDiscreteDynamicsWorld::getCollisionWorld)
			.def("setGravity", &btDiscreteDynamicsWorld::setGravity)
			.def("getGravity", &btDiscreteDynamicsWorld::getGravity)
			.def("addCollisionObject", &btDiscreteDynamicsWorld::addCollisionObject)
			//http://www.rasterbar.com/products/luabind/docs.html#overloaded-functions
			.def("addRigidBody", (void(btDiscreteDynamicsWorld::*)(btRigidBody*)) &btDiscreteDynamicsWorld::addRigidBody)
			.def("addRigidBody", (void(btDiscreteDynamicsWorld::*)(btRigidBody*, short, short)) &btDiscreteDynamicsWorld::addRigidBody)
			.def("removeRigidBody", &btDiscreteDynamicsWorld::removeRigidBody)
			.def("removeCollisionObject", &btDiscreteDynamicsWorld::removeCollisionObject)
			.def("debugDrawConstraint", &btDiscreteDynamicsWorld::debugDrawConstraint)
			.def("debugDrawWorld", &btDiscreteDynamicsWorld::debugDrawWorld)
			.def("setConstraintSolver", &btDiscreteDynamicsWorld::setConstraintSolver)
			.def("getConstraintSolver", &btDiscreteDynamicsWorld::getConstraintSolver)
			.def("getNumConstraints", &btDiscreteDynamicsWorld::getNumConstraints)
			.def("getConstraint", &getConstraintConst)
			.def("getConstraint", &getConstraintNonConst)
			.def("getWorldType", &btDiscreteDynamicsWorld::getWorldType)
			.def("clearForces", &btDiscreteDynamicsWorld::clearForces)
			.def("applyGravity", &btDiscreteDynamicsWorld::applyGravity)
			.def("setNumTasks", &btDiscreteDynamicsWorld::setNumTasks)
			.def("updateVehicles", &btDiscreteDynamicsWorld::updateVehicles)
			.def("addVehicle", &btDiscreteDynamicsWorld::addVehicle)
			.def("removeVehicle", &btDiscreteDynamicsWorld::removeVehicle)
			.def("addCharacter", &btDiscreteDynamicsWorld::addCharacter)
			.def("removeCharacter", &btDiscreteDynamicsWorld::removeCharacter)
			.def("setSynchronizeAllMotionStates", &btDiscreteDynamicsWorld::setSynchronizeAllMotionStates)
			.def("getSynchronizeAllMotionStates", &btDiscreteDynamicsWorld::getSynchronizeAllMotionStates)
			.def("setApplySpeculativeContactRestitution", &btDiscreteDynamicsWorld::setApplySpeculativeContactRestitution)
			.def("getApplySpeculativeContactRestitution", &btDiscreteDynamicsWorld::getApplySpeculativeContactRestitution)
			.def("serialize", &btDiscreteDynamicsWorld::serialize)
	    ;
}
