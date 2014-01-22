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
#include "CollisionShapes.h"
#include "../OverrideosgLuabind.h"

// Library/third-party includes
#include <luabind/class.hpp>

#include <osgbCollision/CollisionShapes.h>

#include <osg/Node>

// Standard includes
// - none




luabind::scope btSphereCollisionShapeFromOSG()
{
    using namespace luabind;
    return def("btSphereCollisionShapeFromOSG", &osgbCollision::btSphereCollisionShapeFromOSG);
}

static btBoxShape * btBoxCollisionShapeFromOSGDefault(osg::Node * n) {
	return osgbCollision::btBoxCollisionShapeFromOSG(n);
}

luabind::scope btBoxCollisionShapeFromOSG()
{
    using namespace luabind;
    return def("btBoxCollisionShapeFromOSG", &osgbCollision::btBoxCollisionShapeFromOSG),
		def("btBoxCollisionShapeFromOSG", &btBoxCollisionShapeFromOSGDefault);
}

luabind::scope btCylinderCollisionShapeFromOSG()
{
    using namespace luabind;
    return def("btCylinderCollisionShapeFromOSG", &osgbCollision::btCylinderCollisionShapeFromOSG);
}

luabind::scope btTriMeshCollisionShapeFromOSG()
{
    using namespace luabind;
    return def("btTriMeshCollisionShapeFromOSG", &osgbCollision::btTriMeshCollisionShapeFromOSG);
}

luabind::scope btConvexTriMeshCollisionShapeFromOSG()
{
    using namespace luabind;
    return def("btConvexTriMeshCollisionShapeFromOSG", &osgbCollision::btConvexTriMeshCollisionShapeFromOSG);
}

luabind::scope btConvexHullCollisionShapeFromOSG()
{
    using namespace luabind;
    return def("btConvexHullCollisionShapeFromOSG", &osgbCollision::btConvexHullCollisionShapeFromOSG);
}

luabind::scope btCompoundShapeFromOSGGeodes()
{
    using namespace luabind;
    return def("btCompoundShapeFromOSGGeodes", &osgbCollision::btCompoundShapeFromOSGGeodes);
}

luabind::scope btCompoundShapeFromOSGGeometry()
{
    using namespace luabind;
    return def("btCompoundShapeFromOSGGeometry", &osgbCollision::btCompoundShapeFromOSGGeometry);
}

luabind::scope btCompoundShapeFromBounds()
{
    using namespace luabind;
    return def("btCompoundShapeFromBounds", &osgbCollision::btCompoundShapeFromBounds);
}

///@TODO: bind the rest of these...

