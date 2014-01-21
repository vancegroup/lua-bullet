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

#include <osgbCollision/ComputeCylinderVisitor.h>

#include <osg/Geode>

// Standard includes
// - none


template<> luabind::scope getLuaBinding<osgbCollision::ComputeCylinderVisitor>() {
	using namespace luabind;

	return
	    class_<osgbCollision::ComputeCylinderVisitor, osg::NodeVisitor> ("ComputeCylinderVisitor")
	    .def(constructor<osg::NodeVisitor::TraversalMode>())
	    .def("reset", &osgbCollision::ComputeCylinderVisitor::reset)
	    .def("setAxis", &osgbCollision::ComputeCylinderVisitor::setAxis)
	    .def("getBoundingCylinder", &osgbCollision::ComputeCylinderVisitor::getBoundingCylinder)
	    //http://www.rasterbar.com/products/luabind/docs.html#overloaded-functions
	    .def("apply", (void(osgbCollision::ComputeCylinderVisitor::*)(osg::Transform&)) &osgbCollision::ComputeCylinderVisitor::apply)
	    .def("apply", (void(osgbCollision::ComputeCylinderVisitor::*)(osg::Geode&)) &osgbCollision::ComputeCylinderVisitor::apply)
	    .def("pushMatrix", &osgbCollision::ComputeCylinderVisitor::pushMatrix)
	    .def("popMatrix", &osgbCollision::ComputeCylinderVisitor::popMatrix)
	    .def("applyDrawable", &osgbCollision::ComputeCylinderVisitor::applyDrawable)
	    ;
}
