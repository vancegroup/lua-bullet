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
#include "BindingFwd.h"

// Library/third-party includes
#include <luabind/class.hpp>

#include <osgbDynamics/CreationRecord.h>

// Standard includes
// - none

template<> luabind::scope getLuaBinding<osgbDynamics::CreationRecord>() {
	using namespace luabind;

	return
	    class_<osgbDynamics::CreationRecord> ("CreationRecord")
	    .def(constructor<>())
	    .def("setMargin", &osgbDynamics::CreationRecord::setMargin)
	    ;
}
