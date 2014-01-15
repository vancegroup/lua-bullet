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
#include <LinearMath/btPoolAllocator.h>


// Standard includes
// - none


namespace {
    const btPersistentManifold* getManifoldByIndexInternalConst(btCollisionDispatcher const * b, int index) {
        return b->getManifoldByIndexInternal(index);
    }
    btPersistentManifold* getManifoldByIndexInternalNonConst(btCollisionDispatcher * b, int index) {
        return b->getManifoldByIndexInternal(index);
    }

    const btCollisionConfiguration* getCollisionConfigurationConst(btCollisionDispatcher const * b) {
        return b->getCollisionConfiguration();
    }
    btCollisionConfiguration* getCollisionConfigurationNonConst(btCollisionDispatcher * b) {
        return b->getCollisionConfiguration();
    }

    const btPoolAllocator* getInternalManifoldPoolConst(btCollisionDispatcher const * b) {
        return b->getInternalManifoldPool();
    }
    btPoolAllocator* getInternalManifoldPoolNonConst(btCollisionDispatcher * b) {
        return b->getInternalManifoldPool();
    }
}

template<> luabind::scope getLuaBinding<btCollisionDispatcher>() {
	using namespace luabind;

	return
	    class_<btCollisionDispatcher, btDispatcher> ("btCollisionDispatcher")
	    .def(constructor<btCollisionConfiguration *>())
	    .def("getDispatcherFlags", &btCollisionDispatcher::getDispatcherFlags)
	    .def("setDispatcherFlags", &btCollisionDispatcher::setDispatcherFlags)
	    .def("registerCollisionCreateFunc", &btCollisionDispatcher::registerCollisionCreateFunc)
	    .def("getNumManifolds", &btCollisionDispatcher::getNumManifolds)
	    .def("getInternalManifoldPointer", &btCollisionDispatcher::getInternalManifoldPointer)
	    .def("getManifoldByIndexInternal", &getManifoldByIndexInternalConst)
	    .def("getManifoldByIndexInternal", &getManifoldByIndexInternalNonConst)
        .def("getNewManifold", &btCollisionDispatcher::getNewManifold)
        .def("releaseManifold", &btCollisionDispatcher::releaseManifold)
        .def("clearManifold", &btCollisionDispatcher::clearManifold)
        .def("findAlgorithm", &btCollisionDispatcher::findAlgorithm)
        .def("needsCollision", &btCollisionDispatcher::needsCollision)
        .def("needsResponse", &btCollisionDispatcher::needsResponse)
        .def("dispatchAllCollisionPairs", &btCollisionDispatcher::dispatchAllCollisionPairs)
        ///@TODO: get this working
        //.def("setNearCallback", &btCollisionDispatcher::setNearCallback)
        //.def("getNearCallback", &btCollisionDispatcher::getNearCallback)
        .def("allocateCollisionAlgorithm", &btCollisionDispatcher::allocateCollisionAlgorithm)
        .def("freeCollisionAlgorithm", &btCollisionDispatcher::freeCollisionAlgorithm)
        .def("getCollisionConfiguration", &getCollisionConfigurationConst)
        .def("getCollisionConfiguration", &getCollisionConfigurationNonConst)
        .def("setCollisionConfiguration", &btCollisionDispatcher::setCollisionConfiguration)
        .def("getInternalManifoldPool", &getInternalManifoldPoolConst)
        .def("getInternalManifoldPool", &getInternalManifoldPoolNonConst)
	    ;
}
