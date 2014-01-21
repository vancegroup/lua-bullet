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

#include <osgbDynamics/MotionState.h>
#include <osgbDynamics/TripleBuffer.h>

// Standard includes
// - none

namespace {
    const osg::Transform* getTransformConst(osgbDynamics::MotionState const * b) {
        return b->getTransform();
    }
    osg::Transform* getTransformNonConst(osgbDynamics::MotionState * b) {
        return b->getTransform();
    }
}

template<> luabind::scope getLuaBinding<osgbDynamics::MotionState>() {
	using namespace luabind;

	return
	    class_<osgbDynamics::MotionState, btMotionState> ("MotionState")
	    .def(constructor<osg::Matrix, osg::Vec3>())
	    .def("setWorldTransform", &osgbDynamics::MotionState::setWorldTransform)
	    .def("getWorldTransform", &osgbDynamics::MotionState::getWorldTransform)
	    .def("computeCOLocalToOsgLocal", &osgbDynamics::MotionState::computeCOLocalToOsgLocal)
	    .def("computeOsgLocalToCOLocal", &osgbDynamics::MotionState::computeOsgLocalToCOLocal)
	    .def("computeOsgWorldToCOLocal", &osgbDynamics::MotionState::computeOsgWorldToCOLocal)
	    .def("computeOsgWorldToBulletWorld", &osgbDynamics::MotionState::computeOsgWorldToBulletWorld)
	    .def("setTransform", &osgbDynamics::MotionState::setTransform)
	    .def("getTransform", &getTransformConst)
	    .def("getTransform", &getTransformNonConst)
	    .def("setParentTransform", &osgbDynamics::MotionState::setParentTransform)
	    .def("getParentTransform", &osgbDynamics::MotionState::getParentTransform)
	    .def("setCenterOfMass", &osgbDynamics::MotionState::setCenterOfMass)
	    .def("getCenterOfMass", &osgbDynamics::MotionState::getCenterOfMass)
	    .def("setScale", &osgbDynamics::MotionState::setScale)
	    .def("getScale", &osgbDynamics::MotionState::getScale)
	    .def("getCallbackList", &osgbDynamics::MotionState::getCallbackList)
	    .def("resetTransform", &osgbDynamics::MotionState::resetTransform)
	    .def("registerTripleBuffer", &osgbDynamics::MotionState::registerTripleBuffer)
	    .def("updateTripleBuffer", &osgbDynamics::MotionState::updateTripleBuffer)
	    ;
}
