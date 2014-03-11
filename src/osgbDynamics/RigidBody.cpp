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
static osg::ref_ptr<osgbDynamics::CreationRecord> crFromTable(luabind::argument t) {

	if (luabind::type(t) != LUA_TTABLE) {
		throw std::runtime_error("Must pass a table of arguments!");
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
	if (t["mass"]) {
		c->_mass = object_cast<float>(t["mass"]);
	}
	if (t["restitution"]) {
		c->_restitution = object_cast<float>(t["restitution"]);
	}
	if (t["friction"]) {
		c->_friction = object_cast<float>(t["friction"]);
	}
	if (t["shapeType"]) {
		c->_shapeType = object_cast<BroadphaseNativeTypes>(t["shapeType"]);
	}
	/// @todo I think there are a few more fields here that might be useful.

	return c;
}
static btRigidBody * createRigidBodyNicely(luabind::argument t) {
	osg::ref_ptr<osgbDynamics::CreationRecord> c = crFromTable(t);
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

static btCollisionShape * createCollisionShapeNicely(luabind::argument t) {
	osg::ref_ptr<osgbDynamics::CreationRecord> c = crFromTable(t);
	return osgbDynamics::createCollisionShape(c.get());
}

luabind::scope getLuaBinding_osgbDynamicsRigidBody() {
	using namespace luabind;

	return def("createRigidBody", &createRigidBodyProtected),
		def("createCollisionShape", &createCollisionShapeNicely);
}
