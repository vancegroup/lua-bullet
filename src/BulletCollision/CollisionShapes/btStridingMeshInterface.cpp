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

#include <BulletCollision/CollisionShapes/btStridingMeshInterface.h>

// Standard includes
// - none



template<> luabind::scope getLuaBinding<btStridingMeshInterface>() {
	using namespace luabind;

	return
	    class_<btStridingMeshInterface> ("btStridingMeshInterface")
		///@todo: Get this working (if needed)
	    //.def(constructor<>())
	    /*.def("InternalProcessAllTriangles", &btStridingMeshInterface::InternalProcessAllTriangles)
		.def("calculateAabbBruteForce", &btStridingMeshInterface::calculateAabbBruteForce)
		.def("getLockedVertexIndexBase", &btStridingMeshInterface::getLockedVertexIndexBase)
		.def("getLockedReadOnlyVertexIndexBase", &btStridingMeshInterface::getLockedReadOnlyVertexIndexBase)
		.def("unLockVertexBase", &btStridingMeshInterface::unLockVertexBase)
		.def("unLockReadOnlyVertexBase", &btStridingMeshInterface::unLockReadOnlyVertexBase)
		.def("getNumSubParts", &btStridingMeshInterface::getNumSubParts)
		.def("preallocateVertices", &btStridingMeshInterface::preallocateVertices)
		.def("preallocateIndices", &btStridingMeshInterface::preallocateIndices)
		.def("hasPremadeAabb", &btStridingMeshInterface::hasPremadeAabb)
		.def("setPremadeAabb", &btStridingMeshInterface::setPremadeAabb)
		.def("getPremadeAabb", &btStridingMeshInterface::getPremadeAabb)
		//.def("getScaling", &btStridingMeshInterface::getScaling)
		.def("setScaling", &btStridingMeshInterface::setScaling)
		.def("calculateSerializeBufferSize", &btStridingMeshInterface::calculateSerializeBufferSize)
		//.def("serialize", &btStridingMeshInterface::serialize)*/
	    ;
}
