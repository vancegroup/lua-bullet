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
#include "../OverrideosgLuabind.h"

// Library/third-party includes
#include <luabind/class.hpp>

#include <osgbDynamics/CreationRecord.h>
#include <osg/Node>

// Standard includes
// - none

template<typename ClassT, typename MemberT, MemberT ClassT::*Member>
static void fieldSetter(ClassT &instance, MemberT & newval) {
	instance.*Member = newval;
}

template<typename ClassT, typename MemberT, MemberT ClassT::*Member>
static MemberT fieldGetter(ClassT const &instance) {
	return instance.*Member;
}

static bool checkRecord(osgbDynamics::CreationRecord const& cr) {
	std::cout << "sceneGraph: " << cr._sceneGraph << std::endl;
	return cr._sceneGraph;
}

template<> luabind::scope getLuaBinding<osgbDynamics::CreationRecord>() {
	using namespace luabind;

	return
	    class_<osgbDynamics::CreationRecord> ("CreationRecord")
	    .def(constructor<>())
	    .def("setCenterOfMass", &osgbDynamics::CreationRecord::setCenterOfMass)
	    .def("setMargin", &osgbDynamics::CreationRecord::setMargin)
	    .def_readwrite("sceneGraph", &osgbDynamics::CreationRecord::_sceneGraph)
		/*
		.property("sceneGraph", &fieldGetter<osgbDynamics::CreationRecord, osg::Node *, &osgbDynamics::CreationRecord::_sceneGraph>,
			&fieldSetter<osgbDynamics::CreationRecord, osg::Node *, &osgbDynamics::CreationRecord::_sceneGraph>)
			*/
	    .def_readwrite("version", &osgbDynamics::CreationRecord::_version)
	    .def_readwrite("com", &osgbDynamics::CreationRecord::_com)
	    .def_readwrite("comSet", &osgbDynamics::CreationRecord::_comSet)
	    .def_readwrite("margin", &osgbDynamics::CreationRecord::_margin)
	    .def_readwrite("marginSet", &osgbDynamics::CreationRecord::_marginSet)
	    .def_readwrite("scale", &osgbDynamics::CreationRecord::_scale)
	    .def_readwrite("parentTransform", &osgbDynamics::CreationRecord::_parentTransform)
	    .def_readwrite("shapeType", &osgbDynamics::CreationRecord::_shapeType)
	    .def_readwrite("mass", &osgbDynamics::CreationRecord::_mass)
	    .def_readwrite("restitution", &osgbDynamics::CreationRecord::_restitution)
	    .def_readwrite("friction", &osgbDynamics::CreationRecord::_friction)
	    .def_readwrite("axis", &osgbDynamics::CreationRecord::_axis)
	    .def_readwrite("reductionLevel", &osgbDynamics::CreationRecord::_reductionLevel)
	    .def_readwrite("overall", &osgbDynamics::CreationRecord::_overall)
		,
		def("checkRecord", &checkRecord)
	    ;
}
