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

namespace {
    const osgbDynamics::PhysicsData* getPhysicsDataConst(osgbDynamics::PhysicsState const * b, const std::string &id) {
        return b->getPhysicsData(id);
    }
    osgbDynamics::PhysicsData* getPhysicsDataNonConst(osgbDynamics::PhysicsState * b, const std::string &id) {
        return b->getPhysicsData(id);
    }
}

template<> luabind::scope getLuaBinding<osgbDynamics::PhysicsState>() {
	using namespace luabind;

	return
	    class_<osgbDynamics::PhysicsState> ("PhysicsState")
	    .def(constructor<>())
	    .def(constructor<osgbDynamics::PhysicsState&, osg::CopyOp>())
	    //http://www.rasterbar.com/products/luabind/docs.html#overloaded-functions
	    .def("addPhysicsData", (void(osgbDynamics::PhysicsState::*)(const osgwTools::RefID*, osgbDynamics::PhysicsData*)) &osgbDynamics::PhysicsState::addPhysicsData)
	    .def("addPhysicsData", (void(osgbDynamics::PhysicsState::*)(const osgwTools::RefID*, const btRigidBody*)) &osgbDynamics::PhysicsState::addPhysicsData)
	    .def("addPhysicsData", (void(osgbDynamics::PhysicsState::*)(const osgwTools::RefID*, const osgbDynamics::CreationRecord*)) &osgbDynamics::PhysicsState::addPhysicsData)
	    .def("addPhysicsData", (void(osgbDynamics::PhysicsState::*)(const osgwTools::RefID*, const std::string&)) &osgbDynamics::PhysicsState::addPhysicsData)
	    .def("addPhysicsData", (void(osgbDynamics::PhysicsState::*)(const std::string&, osgbDynamics::PhysicsData*)) &osgbDynamics::PhysicsState::addPhysicsData)
	    .def("addPhysicsData", (void(osgbDynamics::PhysicsState::*)(const std::string&, const btRigidBody*)) &osgbDynamics::PhysicsState::addPhysicsData)
	    .def("addPhysicsData", (void(osgbDynamics::PhysicsState::*)(const std::string&, const osgbDynamics::CreationRecord*)) &osgbDynamics::PhysicsState::addPhysicsData)
	    .def("addPhysicsData", (void(osgbDynamics::PhysicsState::*)(const std::string&, const std::string&)) &osgbDynamics::PhysicsState::addPhysicsData)
	    .def("getNumEntries", &osgbDynamics::PhysicsState::getNumEntries)
	    //http://www.rasterbar.com/products/luabind/docs.html#overloaded-functions
	    ///@TODO: get this working
	    /*
	    .def("getPhysicsData", (const osgbDynamics::PhysicsData*(osgbDynamics::PhysicsState::*)(const osgwTools::RefID*)) &osgbDynamics::PhysicsState::getPhysicsData)
	    .def("getPhysicsData", (const osgbDynamics::PhysicsData*(osgbDynamics::PhysicsState::*)(const std::string&)) &getPhysicsDataConst)
	    .def("getPhysicsData", (const osgbDynamics::PhysicsData*(osgbDynamics::PhysicsState::*)(const std::string&)) &getPhysicsDataNonConst)
	    */
	    ;
}
