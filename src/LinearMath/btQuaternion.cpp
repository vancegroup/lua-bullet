/**
	@file
	@brief Implementation

	@date 2014

	@author
	Leif Berg
	<lpberg@iastate.edu>
	Iowa State University Virtual Reality Applications Center
	Human-Computer Interaction Graduate Program
*/

//          Copyright Iowa State University 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


// Internal Includes
#include "../BindingFwd.h"

// Library/third-party includes
#include <luabind/class.hpp>

#include <LinearMath/btQuaternion.h>

// Standard includes
// - none

template<> luabind::scope getLuaBinding<btQuaternion>() {
	using namespace luabind;

	return
		class_<btQuaternion,btQuadWord>("btQuaternion")
		.def(constructor<>())
	    .def(constructor<const btScalar&,const btScalar&,const btScalar&,const btScalar&>())
		.def(constructor<const btVector3&, const btScalar&>())
		.def(constructor<const btScalar&,const btScalar&,const btScalar&>())
		.def("setRotation",&btQuaternion::setRotation)
		.def("setEuler",&btQuaternion::setEuler)
		.def("setEulerZYX",&btQuaternion::setEulerZYX)
		.def("length2",&btQuaternion::length2)
		.def("normalize",&btQuaternion::normalize)
		.def("normalized",&btQuaternion::normalized)
		.def("angle",&btQuaternion::angle)
		.def("angleShortestPath",&btQuaternion::angleShortestPath)
		.def("getAngle",&btQuaternion::getAngle)
		.def("getAngleShortestPath",&btQuaternion::getAngleShortestPath)
		.def("getAxis",&btQuaternion::getAxis)
		.def("farthest",&btQuaternion::farthest)
		.def("nearest",&btQuaternion::nearest)
		.def("getW",&btQuaternion::getW)
		.def("dot",&btQuaternion::dot)
		.def("length", &btQuaternion::length)
		.def("inverse", &btQuaternion::inverse)
		.def("slerp", &btQuaternion::slerp)
		;
}
