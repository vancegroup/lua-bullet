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

#include <osgbDynamics/CreationRecord.h>
#include <osg/Node>


// Standard includes
// - none



template<> luabind::scope getLuaBinding<osgbDynamics::CreationRecord>() {
	using namespace luabind;

	return
	    class_<osgbDynamics::CreationRecord> ("CreationRecord")
	    .def(constructor<>())
	    .def("setCenterOfMass", &osgbDynamics::CreationRecord::setCenterOfMass)
	    .def("setMargin", &osgbDynamics::CreationRecord::setMargin)
	    .property("sceneGraph", &osgbDynamics::CreationRecord::_sceneGraph)
	    .property("version", &osgbDynamics::CreationRecord::_version)
	    .property("com", &osgbDynamics::CreationRecord::_com)
	    .property("comSet", &osgbDynamics::CreationRecord::_comSet)
	    .property("margin", &osgbDynamics::CreationRecord::_margin)
	    .property("marginSet", &osgbDynamics::CreationRecord::_marginSet)
	    .property("scale", &osgbDynamics::CreationRecord::_scale)
	    .property("parentTransform", &osgbDynamics::CreationRecord::_parentTransform)
	    .property("shapeType", &osgbDynamics::CreationRecord::_shapeType)
	    .property("mass", &osgbDynamics::CreationRecord::_mass)
	    .property("restitution", &osgbDynamics::CreationRecord::_restitution)
	    .property("friction", &osgbDynamics::CreationRecord::_friction)
	    .property("axis", &osgbDynamics::CreationRecord::_axis)
	    .property("reductionLevel", &osgbDynamics::CreationRecord::_reductionLevel)
	    .property("overall", &osgbDynamics::CreationRecord::_overall)
	    ;
}
