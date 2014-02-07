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
#include <luabind/luabind.hpp>
#include <osg/Node>
#include <osgLua/osgLuabind>

#include <osgbDynamics/RigidBody.h>


// Standard includes
// - none
#include <iostream>

static btRigidBody * createRigidBodyNicely(luabind::argument t) {
	if (luabind::type(t) != LUA_TTABLE) {
		throw std::runtime_error("Must pass a table of arguments to createRigidBody!");
	}
	osg::ref_ptr<osgbDynamics::CreationRecord> c(new osgbDynamics::CreationRecord);
	using luabind::object_cast;

	c->_sceneGraph = object_cast<osg::Node *>(t["sceneGraph"]);
	if (t["com"]) {
		c->setCenterOfMass(object_cast<osg::Vec3>(t["com"]));
	}
	if (t["margin"]) {
		c->setMargin(object_cast<float>(t["margin"]));
	}
	/// @todo I think there are a few more fields here that might be useful.

	// Choose the unary or binary createRigidBody overload.
	if (t["collisionShape"]) {
		return osgbDynamics::createRigidBody(c.get(), luabind::object_cast<btCollisionShape*>(t["collisionShape"]));
	}
	return osgbDynamics::createRigidBody(c.get());

}

static btRigidBody * createRigidBodyProtected(luabind::argument t) {
	btRigidBody * rb = createRigidBodyNicely(t);
	if (!rb) {
		std::cout << "GOT NULL!" << std::endl;
	}
	return rb;
}

luabind::scope getLuaBinding_osgbDynamicsRigidBody() {
	using namespace luabind;

	return def("createRigidBody", &createRigidBodyProtected);
}
