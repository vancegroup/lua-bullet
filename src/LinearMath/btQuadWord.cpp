/**
	@file
	@brief Implementation

	@date 2014

	@author
	Leif Berg
	<lpberg@iastate.edu>
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

#include <LinearMath/btQuadWord.h>

// Standard includes
// - none

template<> luabind::scope getLuaBinding<btQuadWord>() {
	using namespace luabind;

	return
		class_<btQuadWord>("btQuadWord")
		.def(constructor<>())
		.def(constructor<const btScalar&, const btScalar&, const btScalar&>())
		.def(constructor<const btScalar&, const btScalar&, const btScalar&, const btScalar&>())
		.def(constructor<const btScalar&, const btScalar&, const btScalar&>())
		.def("getX",&btQuadWord::getX)
		.def("getY",&btQuadWord::getY)
		.def("getZ",&btQuadWord::getZ)
		.def("setX",&btQuadWord::setX)
		.def("setY",&btQuadWord::setY)
		.def("setZ",&btQuadWord::setZ)
		.def("setW",&btQuadWord::setW)
		.def("x",&btQuadWord::x)
		.def("y",&btQuadWord::y)
		.def("z",&btQuadWord::z)
		.def("w",&btQuadWord::w)
		.def("setMax",&btQuadWord::setMax)
		.def("setMin",&btQuadWord::setMin)
		;
}
