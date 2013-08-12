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

#include <osgbDynamics/PhysicsState.h>


// Standard includes
// - none


template<> luabind::scope getLuaBinding<osgbDynamics::PhysicsData>() {
	using namespace luabind;

	return
	    class_<osgbDynamics::PhysicsData> ("PhysicsData")
	    ///@TODO: figure out how to deal with the protected destructor
	    //.def(constructor<>())
	    //.def(constructor<const osgbDynamics::PhysicsData&, osg::CopyOp>())
	    .def("loadState", &osgbDynamics::PhysicsData::loadState)
	    .def("restoreState", &osgbDynamics::PhysicsData::restoreState)
	    .def("getVersion", &osgbDynamics::PhysicsData::getVersion)
	    ;
}
