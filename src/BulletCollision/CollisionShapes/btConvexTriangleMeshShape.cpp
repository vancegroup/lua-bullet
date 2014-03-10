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

#include <BulletCollision/CollisionShapes/btConvexTriangleMeshShape.h>

// Standard includes
// - none



template<> luabind::scope getLuaBinding<btConvexTriangleMeshShape>() {
	using namespace luabind;

	return
	    class_<btConvexTriangleMeshShape, btPolyhedralConvexAabbCachingShape> ("btConvexTriangleMeshShape")
	    .def(constructor<btStridingMeshInterface *, bool>())
		.def("localGetSupportingVertex", &btConvexTriangleMeshShape::localGetSupportingVertex)
		.def("localGetSupportingVertexWithoutMargin", &btConvexTriangleMeshShape::localGetSupportingVertexWithoutMargin)
		.def("batchedUnitVectorGetSupportingVertexWithoutMargin", &btConvexTriangleMeshShape::batchedUnitVectorGetSupportingVertexWithoutMargin)
		.def("getName", &btConvexTriangleMeshShape::getName)
		.def("getNumVertices", &btConvexTriangleMeshShape::getNumVertices)
		.def("getNumEdges", &btConvexTriangleMeshShape::getNumEdges)
		.def("getEdge", &btConvexTriangleMeshShape::getEdge)
		.def("getVertex", &btConvexTriangleMeshShape::getVertex)
		.def("getNumPlanes", &btConvexTriangleMeshShape::getNumPlanes)
		.def("getPlane", &btConvexTriangleMeshShape::getPlane)
		.def("isInside", &btConvexTriangleMeshShape::isInside)
		.def("setLocalScaling", &btConvexTriangleMeshShape::setLocalScaling)
		.def("getLocalScaling", &btConvexTriangleMeshShape::getLocalScaling)
		.def("calculatePrincipalAxisTransform", &btConvexTriangleMeshShape::calculatePrincipalAxisTransform)
	    ;
}
