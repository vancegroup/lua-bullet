/**
	@file
	@brief Implementation

	@date 2014

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

#include <BulletCollision/CollisionDispatch/btActivatingCollisionAlgorithm.h>


// Standard includes
// - none



template<> luabind::scope getLuaBinding<btActivatingCollisionAlgorithm>() {
	using namespace luabind;

	return
	    class_<btActivatingCollisionAlgorithm, btCollisionAlgorithm> ("btActivatingCollisionAlgorithm")
	    ;
}
