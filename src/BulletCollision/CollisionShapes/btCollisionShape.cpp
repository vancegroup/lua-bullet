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

#include <BulletCollision/CollisionShapes/btCollisionShape.h>


// Standard includes
// - none



template<> luabind::scope getLuaBinding<btCollisionShape>() {
	using namespace luabind;

	return
	    class_<btCollisionShape> ("btCollisionShape")
	    .def(constructor<>())
	    .def("getAabb", &btCollisionShape::getAabb)
	    ///@TODO: add btScalar binding for these to work
	    //.def("getBoundingSphere", &btCollisionShape::getBoundingSphere)
	    //.def("getAngularMotionDisc", &btCollisionShape::getAngularMotionDisc)
	    //.def("getContactBreakingThreshold", &btCollisionShape::getContactBreakingThreshold)
	    //.def("calculateTemporalAabb", &btCollisionShape::calculateTemporalAabb)
	    .def("isPolyhedral", &btCollisionShape::isPolyhedral)
	    .def("isConvex2d", &btCollisionShape::isConvex2d)
	    .def("isConvex", &btCollisionShape::isConvex)
	    .def("isNonMoving", &btCollisionShape::isNonMoving)
	    .def("isConcave", &btCollisionShape::isConcave)
	    .def("isCompound", &btCollisionShape::isCompound)
	    .def("isSoftBody", &btCollisionShape::isSoftBody)
	    .def("isInfinite", &btCollisionShape::isInfinite)
	    .def("setLocalScaling", &btCollisionShape::setLocalScaling)
	    .def("getLocalScaling", &btCollisionShape::getLocalScaling)
	    //.def("calculateLocalInertia", &btCollisionShape::calculateLocalInertia)
	    .def("getName", &btCollisionShape::getName)
	    .def("getShapeType", &btCollisionShape::getShapeType)
	    .def("getAnisotropicRollingFrictionDirection", &btCollisionShape::getAnisotropicRollingFrictionDirection)
	    //.def("setMargin", &btCollisionShape::setMargin)
	    //.def("getMargin", &btCollisionShape::getMargin)
	    .def("setUserPointer", &btCollisionShape::setUserPointer)
	    .def("getUserPointer", &btCollisionShape::getUserPointer)
	    ///@TODO: add btSerializer binding for these to work
	    //.def("calculateSerializeBufferSize", &btCollisionShape::calculateSerializeBufferSize)
	    //.def("serialize", &btCollisionShape::serialize)
	    //.def("serializeSingleShape", &btCollisionShape::serializeSingleShape)
	    ;
}
