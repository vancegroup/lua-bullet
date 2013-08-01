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

#include <BulletCollision/BroadphaseCollision/btBroadphaseProxy.h>


// Standard includes
// - none



template<> luabind::scope getLuaBinding<btBroadphaseProxy>() {
	using namespace luabind;

	return
	    class_<btBroadphaseProxy> ("btBroadphaseProxy")
	    .def(constructor<>())
	    .def(constructor<const btVector3 &, const btVector3 &, void *, short int, short int, void *>())
	    .def("getUid", &btBroadphaseProxy::getUid)
	    ///@TODO finish binding the rest of these properties if they're needed
	    .property("m_uniqueId", &btBroadphaseProxy::m_uniqueId)
	    .property("m_aabbMin", &btBroadphaseProxy::m_aabbMin)
	    .property("m_aabbMax", &btBroadphaseProxy::m_aabbMax)
	    ;
}
