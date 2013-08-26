/**
	@file
	@brief Header

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

// Library/third-party includes
#include <luabind/class.hpp>

#include <osgbCollision/CollisionShapes.h>

// Standard includes
// - none




luabind::scope btSphereCollisionShapeFromOSG();

luabind::scope btBoxCollisionShapeFromOSG();

luabind::scope btCylinderCollisionShapeFromOSG();

luabind::scope btTriMeshCollisionShapeFromOSG();

luabind::scope btConvexTriMeshCollisionShapeFromOSG();

luabind::scope btConvexHullCollisionShapeFromOSG();

luabind::scope btCompoundShapeFromOSGGeodes();

luabind::scope btCompoundShapeFromOSGGeometry();

luabind::scope btCompoundShapeFromBounds();
