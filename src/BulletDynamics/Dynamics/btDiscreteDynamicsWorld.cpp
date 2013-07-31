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

// Standard includes
// - none



template<> luabind::scope getLuaBinding<btDiscreteDynamicsWorld>() {
	using namespace luabind;

	return
	    class_<btDiscreteDynamicsWorld> ("btDiscreteDynamicsWorld")
	    .def(constructor<btDispatcher *, btBroadphaseInterface *, btConstraintSolver *, btCollisionConfiguration *>())
	    .def("stepSimulation", &btDiscreteDynamicsWorld::stepSimulation)
	    .def("synchronizeMotionStates", &btDiscreteDynamicsWorld::synchronizeMotionStates)
	    .def("synchronizeSingleMotionState", &btDiscreteDynamicsWorld::synchronizeSingleMotionState)
	    .def("addConstraint", &btDiscreteDynamicsWorld::addConstraint)
	    .def("removeConstraint", &btDiscreteDynamicsWorld::removeConstraint)
	    .def("addAction", &btDiscreteDynamicsWorld::addAction)
	    .def("removeAction", &btDiscreteDynamicsWorld::removeAction)
	    ///@TODO figure out how we can bind these appropriately, one normal, one const
	    //.def("getSimulationIsLandManager", &btDiscreteDynamicsWorld::getSimulationIslandManager)
	    .def("getCollisionWorld", &btDiscreteDynamicsWorld::getCollisionWorld)
	    .def("setGravity", &btDiscreteDynamicsWorld::setGravity)
	    .def("getGravity", &btDiscreteDynamicsWorld::getGravity)
	    .def("addCollisionObject", &btDiscreteDynamicsWorld::addCollisionObject)
	    ///@TODO this has two methods available, how to bind this?
	    //.def("addRigidBody", &btDiscreteDynamicsWorld::addRigidBody)
	    .def("removeRigidBody", &btDiscreteDynamicsWorld::removeRigidBody)
	    .def("removeCollisionObject", &btDiscreteDynamicsWorld::removeCollisionObject)
	    .def("debugDrawConstraint", &btDiscreteDynamicsWorld::debugDrawConstraint)
	    .def("debugDrawWorld", &btDiscreteDynamicsWorld::debugDrawWorld)
	    .def("setConstraintSolver", &btDiscreteDynamicsWorld::setConstraintSolver)
	    .def("getConstraintSolver", &btDiscreteDynamicsWorld::getConstraintSolver)
	    .def("getNumConstraints", &btDiscreteDynamicsWorld::getNumConstraints)
	    ///@TODO figure out how we can bind these appropriately, one normal, one const
	    //.def("getConstraint", &btDiscreteDynamicsWorld::getCollisionWorld)
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
	    //.def("serialize", &btDiscreteDynamicsWorld::serialize)
	    ;
}
