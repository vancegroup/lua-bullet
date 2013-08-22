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

#include <BulletCollision/CollisionDispatch/btDefaultCollisionConfiguration.h>
#include <LinearMath/btPoolAllocator.h>
#include <BulletCollision/NarrowPhaseCollision/btVoronoiSimplexSolver.h>
#include <BulletCollision/CollisionDispatch/btCollisionCreateFunc.h>

// Standard includes
// - none



template<> luabind::scope getLuaBinding<btDefaultCollisionConfiguration>() {
	using namespace luabind;

	return
	    class_<btDefaultCollisionConfiguration> ("btDefaultCollisionConfiguration")
	    .def(constructor<btDefaultCollisionConstructionInfo>())
	    .def("getPersistentManifoldPool", &btDefaultCollisionConfiguration::getPersistentManifoldPool)
	    .def("getCollisionAlgorithmPool", &btDefaultCollisionConfiguration::getCollisionAlgorithmPool)
	    .def("getSimplexSolver", &btDefaultCollisionConfiguration::getSimplexSolver)
	    .def("getCollisionAlgorithmCreateFunc", &btDefaultCollisionConfiguration::getCollisionAlgorithmCreateFunc)
	    .def("setConvexMultipointIterations", &btDefaultCollisionConfiguration::setConvexConvexMultipointIterations)
	    .def("setPlaneConvexMultipointIterations", &btDefaultCollisionConfiguration::setPlaneConvexMultipointIterations)
        .scope
        [
            class_<btDefaultCollisionConstructionInfo>("btDefaultCollisionConstructionInfo")
            .def(constructor<>())
            .def_readwrite("persistentManifoldPool", &btDefaultCollisionConstructionInfo::m_persistentManifoldPool)
            .def_readwrite("collisionAlgorithmPool", &btDefaultCollisionConstructionInfo::m_collisionAlgorithmPool)
            .def_readwrite("defaultMaxPersistentManifoldPoolSize", &btDefaultCollisionConstructionInfo::m_defaultMaxPersistentManifoldPoolSize)
            .def_readwrite("defaultMaxCollisionAlgorithmPoolSize", &btDefaultCollisionConstructionInfo::m_defaultMaxCollisionAlgorithmPoolSize)
            .def_readwrite("customCollisionAlgorithmMaxElementSize", &btDefaultCollisionConstructionInfo::m_customCollisionAlgorithmMaxElementSize)
            .def_readwrite("useEpaPenetrationAlgorithm", &btDefaultCollisionConstructionInfo::m_useEpaPenetrationAlgorithm)
        ];
	    ;
}
