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

#include <osgbCollision/CollectVerticesVisitor.h>

#include <osg/Geode>

// Standard includes
// - none


template<> luabind::scope getLuaBinding<osgbCollision::CollectVerticesVisitor>() {
	using namespace luabind;

	return
	    class_<osgbCollision::CollectVerticesVisitor, osg::NodeVisitor> ("CollectVerticesVisitor")
	    .def(constructor<osg::NodeVisitor::TraversalMode>())
	    .def("reset", &osgbCollision::CollectVerticesVisitor::reset)
	    .def("getVertices", &osgbCollision::CollectVerticesVisitor::getVertices)
	    //http://www.rasterbar.com/products/luabind/docs.html#overloaded-functions
	    .def("apply", (void(osgbCollision::CollectVerticesVisitor::*)(osg::Geode&)) &osgbCollision::CollectVerticesVisitor::apply)
	    .def("apply", (void(osgbCollision::CollectVerticesVisitor::*)(osg::Geode&)) &osgbCollision::CollectVerticesVisitor::apply)
	    ;
}
