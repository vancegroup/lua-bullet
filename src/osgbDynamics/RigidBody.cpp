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

#include <osgbDynamics/RigidBody.h>


// Standard includes
// - none
#include <iostream>

static btRigidBody * createRigidBody1Arg(osgbDynamics::CreationRecord* a1) {
	return osgbDynamics::createRigidBody(a1);
}
static btRigidBody * createRigidBody2Arg(osgbDynamics::CreationRecord* a1, btCollisionShape* a2) {
	btRigidBody * rb = osgbDynamics::createRigidBody(a1, a2);
	if (!rb) {
		std::cout << "GOT NULL!" << std::endl;
	}
	return rb;
}
luabind::scope getLuaBinding_osgbDynamicsRigidBody() {
	using namespace luabind;

	return
#if 0
	    def("createRigidBody", static_cast<btRigidBody* (*)(osgbDynamics::CreationRecord*)>(&osgbDynamics::createRigidBody)),
		def("createRigidBody", static_cast<btRigidBody* (*)(osgbDynamics::CreationRecord*, btCollisionShape*)>(&osgbDynamics::createRigidBody)),
#endif
		def("createRigidBody", &createRigidBody1Arg),
		def("createRigidBody", &createRigidBody2Arg),
		scope()
	    ;
}
