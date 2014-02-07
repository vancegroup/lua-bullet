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

namespace {
    const btMatrix3x3& getBasisConst(btTransform const * b) {
        return b->getBasis();
    }
    btMatrix3x3& getBasisNonConst(btTransform * b) {
        return b->getBasis();
    }

    const btVector3& getOriginConst(btTransform const * b) {
        return b->getOrigin();
    }
    btVector3& getOriginNonConst(btTransform * b) {
        return b->getOrigin();
    }
}


template<> luabind::scope getLuaBinding<btTransform>() {
	using namespace luabind;

	return
	    class_<btTransform> ("btTransform")
	    .def(constructor<btQuaternion, btVector3>())
	    .def(constructor<btMatrix3x3, btVector3>())
	    .def(constructor<btTransform>())
		.def(constructor<>())
	    .def("mult", &btTransform::mult)
	    .def("getBasis", &getBasisConst)
	    .def("getBasis", &getBasisNonConst)
	    .def("getOrigin", &getOriginConst)
	    .def("getOrigin", &getOriginNonConst)
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
