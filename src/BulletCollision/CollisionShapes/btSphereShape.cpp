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

#include <BulletCollision/CollisionShapes/btSphereShape.h>

// Standard includes
// - none



template<> luabind::scope getLuaBinding<btSphereShape>() {
	using namespace luabind;

	return
		class_<btSphereShape, btConvexInternalShape> ("btSphereShape")
		.def(constructor<btSphereShape>())
		.def("localGetSupportingVertex", &btSphereShape::localGetSupportingVertex)
		.def("localGetSupportingVertexWithoutMargin", &btSphereShape::localGetSupportingVertexWithoutMargin)
		.def("batchedUnitVectorGetSupportingVertexWithoutMargin", &btSphereShape::batchedUnitVectorGetSupportingVertexWithoutMargin)
		.def("calculateLocalInertia", &btSphereShape::calculateLocalInertia)
		.def("getAabb", &btSphereShape::getAabb)
		.def("getRadius", &btSphereShape::getRadius)
		.def("getName", &btSphereShape::getName)
		.def("setMargin", &btSphereShape::setMargin)
		.def("getMargin", &btSphereShape::getMargin)
	    ;
}
