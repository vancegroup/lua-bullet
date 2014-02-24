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

#include <BulletCollision/CollisionShapes/btStaticPlaneShape.h>

// Standard includes
// - none



template<> luabind::scope getLuaBinding<btStaticPlaneShape>() {
	using namespace luabind;

	return
		class_<btStaticPlaneShape, btConcaveShape> ("btStaticPlaneShape")
		.def(constructor<btStaticPlaneShape>())
		.def("getAabb", &btStaticPlaneShape::getAabb)
		.def("processAllTriangles", &btStaticPlaneShape::processAllTriangles)
		.def("calculateLocalInertia", &btStaticPlaneShape::calculateLocalInertia)
		.def("setLocalScaling", &btStaticPlaneShape::setLocalScaling)
		.def("getLocalScaling", &btStaticPlaneShape::getLocalScaling)
		.def("getPlaneNormal", &btStaticPlaneShape::getPlaneNormal)
		.def("getPlaneConstant", &btStaticPlaneShape::getPlaneConstant)
		.def("getName", &btStaticPlaneShape::getName)
		.def("calculateSerializeBufferSize", &btStaticPlaneShape::calculateSerializeBufferSize)
		.def("serialize", &btStaticPlaneShape::serialize)
	    ;
}
