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

#include <BulletCollision/CollisionDispatch/btCollisionDispatcher.h>
#include <BulletCollision/CollisionDispatch/btCollisionConfiguration.h>
#include <BulletCollision/BroadphaseCollision/btCollisionAlgorithm.h>
#include <BulletCollision/BroadphaseCollision/btOverlappingPairCache.h>


// Standard includes
// - none



template<> luabind::scope getLuaBinding<btCollisionDispatcher>() {
	using namespace luabind;

	return
	    class_<btCollisionDispatcher> ("btCollisionDispatcher")
	    .def(constructor<btCollisionConfiguration *>())
	    .def("getDispatcherFlags", &btCollisionDispatcher::getDispatcherFlags)
	    .def("setDispatcherFlags", &btCollisionDispatcher::setDispatcherFlags)
	    .def("registerCollisionCreateFunc", &btCollisionDispatcher::registerCollisionCreateFunc)
	    .def("getNumManifolds", &btCollisionDispatcher::getNumManifolds)
	    .def("getInternalManifoldPointer", &btCollisionDispatcher::getInternalManifoldPointer)
	    ///@TODO figure out how we can bind these appropriately, two methods one normal and one const
	    //.def("getManifoldByIndexInternal", &btCollisionDispatcher::getManifoldByIndexInternal)
        .def("getNewManifold", &btCollisionDispatcher::getNewManifold)
        .def("releaseManifold", &btCollisionDispatcher::releaseManifold)
        .def("clearManifold", &btCollisionDispatcher::clearManifold)
        .def("findAlgorithm", &btCollisionDispatcher::findAlgorithm)
        .def("needsCollision", &btCollisionDispatcher::needsCollision)
        .def("needsResponse", &btCollisionDispatcher::needsResponse)
        .def("dispatchAllCollisionPairs", &btCollisionDispatcher::dispatchAllCollisionPairs)
        //.def("setNearCallback", &btCollisionDispatcher::setNearCallback)
        //.def("getNearCallback", &btCollisionDispatcher::getNearCallback)
        .def("allocateCollisionAlgorithm", &btCollisionDispatcher::allocateCollisionAlgorithm)
        .def("freeCollisionAlgorithm", &btCollisionDispatcher::freeCollisionAlgorithm)
        ///@TODO figure out how we can bind these appropriately, two methods one normal and one const
        //.def("getCollisionConfiguration", &btCollisionDispatcher::getCollisionConfiguration)
        .def("setCollisionConfiguration", &btCollisionDispatcher::setCollisionConfiguration)
        ///@TODO figure out how we can bind these appropriately, two methods one normal and one const
        //.def("getInternalManifoldPool", &btCollisionDispatcher::getInternalManifoldPool)
	    ;
}
