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

#include <BulletCollision/CollisionShapes/btBoxShape.h>

// Standard includes
// - none



template<> luabind::scope getLuaBinding<btBoxShape>() {
	using namespace luabind;

	return
	    class_<btBoxShape> ("btBoxShape")
	    .def(constructor<const btVector3&>())
	    .def("getHalfExtentsWithMargin", &btBoxShape::getHalfExtentsWithMargin)
	    .def("getHalfExtentsWithoutMargin", &btBoxShape::getHalfExtentsWithoutMargin)
	    .def("localGetSupportingVertex", &btBoxShape::localGetSupportingVertex)
	    .def("batchedUnitVectorGetSupportingVertexWithoutMargin", &btBoxShape::batchedUnitVectorGetSupportingVertexWithoutMargin)
	    .def("setMargin", &btBoxShape::setMargin)
	    .def("setLocalScaling", &btBoxShape::setLocalScaling)
	    .def("getAabb", &btBoxShape::getAabb)
	    .def("calculateLocalInertia", &btBoxShape::calculateLocalInertia)
	    .def("getPlane", &btBoxShape::getPlane)
	    .def("getNumPlanes", &btBoxShape::getNumPlanes)
	    .def("getNumVertices", &btBoxShape::getNumVertices)
	    .def("getNumEdges", &btBoxShape::getNumEdges)
	    .def("getVertex", &btBoxShape::getVertex)
	    .def("getPlaneEquation", &btBoxShape::getPlaneEquation)
	    .def("getEdge", &btBoxShape::getEdge)
	    .def("isInside", &btBoxShape::isInside)
	    .def("getName", &btBoxShape::getName)
	    .def("getNumPreferredPenetrationDirections", &btBoxShape::getNumPreferredPenetrationDirections)
	    .def("getPreferredPenetrationDirection", &btBoxShape::getPreferredPenetrationDirection)
	    ;
}
