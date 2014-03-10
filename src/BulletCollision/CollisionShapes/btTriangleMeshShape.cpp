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

#include <BulletCollision/CollisionShapes/btTriangleMeshShape.h>

// Standard includes
// - none



template<> luabind::scope getLuaBinding<btTriangleMeshShape>() {
	using namespace luabind;

	return
	    class_<btTriangleMeshShape, btConcaveShape> ("btTriangleMeshShape")
	    .def("localGetSupportingVertex", &btTriangleMeshShape::localGetSupportingVertex)
		.def("localGetSupportingVertexWithoutMargin", &btTriangleMeshShape::localGetSupportingVertexWithoutMargin)
		.def("recalcLocalAabb", &btTriangleMeshShape::recalcLocalAabb)
		.def("getAabb", &btTriangleMeshShape::getAabb)
		.def("processAllTriangles", &btTriangleMeshShape::processAllTriangles)
		.def("calculateLocalInertia", &btTriangleMeshShape::calculateLocalInertia)
		.def("setLocalScaling", &btTriangleMeshShape::setLocalScaling)
		//@TODO: fix const non-const
		//.def("getMeshInterface", &btTriangleMeshShape::getMeshInterface)
		//.def("getMeshInterface", &btTriangleMeshShape::getMeshInterface)
		//.def("getLocalAabbMin", &btTriangleMeshShape::getLocalAabbMin)
		//.def("getLocalAabbMax", &btTriangleMeshShape::getLocalAabbMax)
		//.def("getName", &btTriangleMeshShape::getName)
	    ;
}
