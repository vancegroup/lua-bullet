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

#include <osgbDynamics/PhysicsThread.h>
#include <osgbDynamics/TripleBuffer.h>

// Standard includes
// - none



template<> luabind::scope getLuaBinding<osgbDynamics::PhysicsThread>() {
	using namespace luabind;

	return
	    class_<osgbDynamics::PhysicsThread> ("PhysicsThread")
	    .def(constructor<btDynamicsWorld *, osgbDynamics::TripleBuffer *>())
	    .def("setTimeStep", &osgbDynamics::PhysicsThread::setTimeStep)
	    .def("getTimeStep", &osgbDynamics::PhysicsThread::getTimeStep)
	    .def("run", &osgbDynamics::PhysicsThread::run)
	    .def("stopPhysics", &osgbDynamics::PhysicsThread::stopPhysics)
	    .def("pause", &osgbDynamics::PhysicsThread::pause)
	    .def("isPaused", &osgbDynamics::PhysicsThread::isPaused)
	    .def("getDynamicsWorld", &osgbDynamics::PhysicsThread::getDynamicsWorld)
	    ;
}
