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

#include <BulletCollision/CollisionShapes/btCompoundShape.h>
#include <LinearMath/btSerializer.h>

// Standard includes
// - none



template<> luabind::scope getLuaBinding<btCompoundShape>() {
	using namespace luabind;

	return
	    class_<btCompoundShape> ("btCompoundShape")
	    .def(constructor<bool>())
	    .def("addChildShape", &btCompoundShape::addChildShape)
	    .def("removeChildShape", &btCompoundShape::removeChildShape)
	    .def("removeChildShapeByIndex", &btCompoundShape::removeChildShapeByIndex)
	    .def("getNumChildShapes", &btCompoundShape::getNumChildShapes)
	    ///@TODO figure out how we can bind these appropriately, one normal, one const
	    //.def("getChildShape", &btCompoundShape::getChildShape)
	    ///@TODO figure out how we can bind these appropriately, one normal, one const
	    //.def("getChildTransform", &btCompoundShape::getChildTransform)
	    .def("updateChildTransform", &btCompoundShape::updateChildTransform)
	    .def("getChildList", &btCompoundShape::getChildList)
	    .def("getAabb", &btCompoundShape::getAabb)
	    .def("recalculateLocalAabb", &btCompoundShape::recalculateLocalAabb)
	    .def("setLocalScaling", &btCompoundShape::setLocalScaling)
	    .def("getLocalScaling", &btCompoundShape::getLocalScaling)
	    .def("calculateLocalInertia", &btCompoundShape::calculateLocalInertia)
	    .def("setMargin", &btCompoundShape::setMargin)
	    .def("getMargin", &btCompoundShape::getMargin)
	    .def("getName", &btCompoundShape::getName)
	    ///@TODO figure out how we can bind these appropriately, one normal, one const
	    //.def("getDynamicAabbTree", &btCompoundShape::getDynamicAabbTree)
	    .def("createAabbTreeFromChildren", &btCompoundShape::createAabbTreeFromChildren)
	    .def("calculatePrincipalAxisTransform", &btCompoundShape::calculatePrincipalAxisTransform)
	    .def("getUpdateRevision", &btCompoundShape::getUpdateRevision)
	    .def("calculateSerializeBufferSize", &btCompoundShape::calculateSerializeBufferSize)
	    .def("serialize", &btCompoundShape::serialize)
	    ;
}
