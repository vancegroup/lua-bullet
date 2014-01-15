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

#include <BulletCollision/BroadphaseCollision/btAxisSweep3.h>
#include <BulletCollision/BroadphaseCollision/btBroadphaseInterface.h>

// Standard includes
// - none



template<> luabind::scope getLuaBinding<btAxisSweep3>() {
	using namespace luabind;

	return
		class_<btAxisSweep3Internal<unsigned short int> , btBroadphaseInterface> ("btAxisSweep3Internal")
		,
	    class_<btAxisSweep3, btAxisSweep3Internal<unsigned short int> > ("btAxisSweep3")
			.def(constructor<const btVector3 &, const btVector3 &>())
			.def(constructor<const btVector3 &, const btVector3 &, unsigned short int>())
	    ;
}
