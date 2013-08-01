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

#include <LinearMath/btTransform.h>


// Standard includes
// - none



template<> luabind::scope getLuaBinding<btTransform>() {
	using namespace luabind;

	return
	    class_<btTransform> ("btTransform")
	    .def(constructor<const btQuaternion &, const btVector3 &>())
	    .def(constructor<const btMatrix3x3 &, const btVector3 &>())
	    .def(constructor<const btTransform &>())
	    .def("mult", &btTransform::mult)
	    ///@TODO figure out how we can bind these appropriately, one normal, one const
	    //.def("getBasis", &btTransform::getBasis)
	    ///@TODO figure out how we can bind these appropriately, one normal, one const
	    //.def("getOrigin", &btTransform::getOrigin)
	    .def("getRotation", &btTransform::getRotation)
	    .def("setFromOpenGLMatrix", &btTransform::setFromOpenGLMatrix)
	    .def("getOpenGLMatrix", &btTransform::getOpenGLMatrix)
	    .def("setOrigin", &btTransform::setOrigin)
	    .def("invXForm", &btTransform::invXform)
	    .def("setBasis", &btTransform::setBasis)
	    .def("setRotation", &btTransform::setRotation)
	    .def("setIdentity", &btTransform::setIdentity)
	    .def("inverse", &btTransform::inverse)
	    .def("inverseTimes", &btTransform::inverseTimes)
	    .def("serialize", &btTransform::serialize)
	    .def("serializeFloat", &btTransform::serializeFloat)
	    .def("deSerialize", &btTransform::deSerialize)
	    .def("deSerializeDouble", &btTransform::deSerializeDouble)
	    .def("deSerializeFloat", &btTransform::deSerializeFloat)
	    ;
}
