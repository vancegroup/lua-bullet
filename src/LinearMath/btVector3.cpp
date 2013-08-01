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
#include "../BindingFwd.h"

// Library/third-party includes
#include <luabind/class.hpp>

#include <LinearMath/btVector3.h>


// Standard includes
// - none



template<> luabind::scope getLuaBinding<btVector3>() {
	using namespace luabind;

	return
	    class_<btVector3> ("btVector3")
	    .def(constructor<>())
	    .def(constructor<const btScalar &, const btScalar &, const btScalar &>())
	    .def("length2", &btVector3::length2)
	    .def("length", &btVector3::length)
	    .def("distance2", &btVector3::distance2)
	    .def("distance", &btVector3::distance)
	    .def("safeNormalize", &btVector3::safeNormalize)
	    .def("normalize", &btVector3::normalize)
		.def("normalized", &btVector3::normalized)
		.def("rotate", &btVector3::rotate)
		.def("angle", &btVector3::angle)
		.def("absolute", &btVector3::absolute)
		.def("cross", &btVector3::cross)
		.def("triple", &btVector3::triple)
		.def("minAxis", &btVector3::minAxis)
		.def("maxAxis", &btVector3::maxAxis)
		.def("furthestAxis", &btVector3::furthestAxis)
		.def("closestAxis", &btVector3::closestAxis)
		.def("setInterpolate3", &btVector3::setInterpolate3)
		.def("lerp", &btVector3::lerp)
	    .def("getX", &btVector3::getX)
	    .def("getY", &btVector3::getY)
	    .def("getZ", &btVector3::getZ)
	    .def("setX", &btVector3::setX)
	    .def("setY", &btVector3::setY)
	    .def("setZ", &btVector3::setZ)
	    .def("setW", &btVector3::setW)
	    .def("x", &btVector3::x)
	    .def("y", &btVector3::y)
	    .def("z", &btVector3::z)
	    .def("w", &btVector3::w)
	    .def("setMax", &btVector3::setMax)
	    .def("setMin", &btVector3::setMin)
	    .def("setValue", &btVector3::setValue)
	    .def("getSkewSymmetricMatrix", &btVector3::getSkewSymmetricMatrix)
	    .def("setZero", &btVector3::setZero)
	    .def("isZero", &btVector3::isZero)
	    .def("fuzzyZero", &btVector3::fuzzyZero)
	    .def("serialize", &btVector3::serialize)
	    .def("deSerialize", &btVector3::deSerialize)
	    .def("serializeFloat", &btVector3::serializeFloat)
	    .def("deSerializeFloat", &btVector3::deSerializeFloat)
	    .def("serializeDouble", &btVector3::serializeDouble)
	    .def("deSerializeDouble", &btVector3::deSerializeDouble)
	    .def("maxDot", &btVector3::maxDot)
	    .def("minDot", &btVector3::minDot)
	    .def("dot3", &btVector3::dot3)
	    .property("x", &btVector3::getX, &btVector3::setX)
	    .property("y", &btVector3::getY, &btVector3::setY)
	    .property("z", &btVector3::getZ, &btVector3::setZ)
	    ;
}
