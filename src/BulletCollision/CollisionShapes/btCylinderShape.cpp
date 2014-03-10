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

#include <BulletCollision/CollisionShapes/btCylinderShape.h>

// Standard includes
// - none



template<> luabind::scope getLuaBinding<btCylinderShape>() {
	using namespace luabind;

	return
	    class_<btCylinderShape, btConvexInternalShape> ("btCylinderShape")
	    .def(constructor<btVector3>())
	    .def("getHalfExtentsWithMargin", &btCylinderShape::getHalfExtentsWithMargin)
	    .def("getHalfExtentsWithoutMargin", &btCylinderShape::getHalfExtentsWithoutMargin)
	    .def("getAabb", &btCylinderShape::getAabb)
	    .def("calculateLocalInertia", &btCylinderShape::calculateLocalInertia)
		.def("localGetSupportingVertexWithoutMargin", &btCylinderShape::localGetSupportingVertexWithoutMargin)
		.def("batchedUnitVectorGetSupportingVertexWithoutMargin", &btCylinderShape::batchedUnitVectorGetSupportingVertexWithoutMargin)
		.def("setMargin", &btCylinderShape::setMargin)
		.def("localGetSupportingVertex", &btCylinderShape::localGetSupportingVertex)
		.def("getUpAxis", &btCylinderShape::getUpAxis)
		.def("getAnisotropicRollingFrictionDirection", &btCylinderShape::getAnisotropicRollingFrictionDirection)
		.def("getRadius", &btCylinderShape::getRadius)
		.def("setLocalScaling", &btCylinderShape::setLocalScaling)
		.def("getName", &btCylinderShape::getName)
		.def("calculateSerializeBufferSize", &btCylinderShape::calculateSerializeBufferSize)
		.def("serialize", &btCylinderShape::serialize)
	    ;
}
