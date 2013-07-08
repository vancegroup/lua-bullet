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
#include <LinearMath/btAlignedAllocator.h>


// Standard includes
// - none

//namespace LinearMath {
//	class btVector3;
//}


template<> luabind::scope getLuaBinding<btVector3>() {
	using namespace luabind;

	return
	    class_<btVector3> ("btVector3")
	    .def(constructor<>())
	    .def("setX", &btVector3::setX)
	    .def("setY", &btVector3::setY)
	    .def("setZ", &btVector3::setZ)
	    ;
}
