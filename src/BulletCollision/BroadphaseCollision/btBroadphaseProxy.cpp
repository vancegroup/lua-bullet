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
#include "../../BindingFwd.h"

// Library/third-party includes
#include <luabind/class.hpp>

#include <BulletCollision/BroadphaseCollision/btBroadphaseProxy.h>


// Standard includes
// - none



template<> luabind::scope getLuaBinding<btBroadphaseProxy>() {
	using namespace luabind;

	return
	    class_<btBroadphaseProxy> ("btBroadphaseProxy")
	    .def(constructor<>())
	    .def(constructor<btVector3, btVector3, void *, short int, short int, void *>())
	    .def("getUid", &btBroadphaseProxy::getUid)
	    ///@TODO finish binding the rest of the properties if they're needed
		/*
	    .def_readwrite("m_uniqueId", &btBroadphaseProxy::m_uniqueId)
	    .def_readwrite("m_aabbMin", &btBroadphaseProxy::m_aabbMin)
	    .def_readwrite("m_aabbMax", &btBroadphaseProxy::m_aabbMax)
		*/
	    //http://www.rasterbar.com/products/luabind/docs.html#enums
	    //add binding for various enums
	    ///@TODO is this the correct way to bind these enums since they're global?
	    .enum_("BroadphaseNativeTypes")
	    [
            value("BOX_SHAPE_PROXYTYPE", BOX_SHAPE_PROXYTYPE),
            value("TRIANGLE_SHAPE_PROXYTYPE", TRIANGLE_SHAPE_PROXYTYPE),
            value("TETRAHEDRAL_SHAPE_PROXYTYPE", TETRAHEDRAL_SHAPE_PROXYTYPE),
            value("CONVEX_TRIANGLEMESH_SHAPE_PROXYTYPE", CONVEX_TRIANGLEMESH_SHAPE_PROXYTYPE),
            value("CONVEX_HULL_SHAPE_PROXYTYPE", CONVEX_HULL_SHAPE_PROXYTYPE),
            value("CONVEX_POINT_CLOUD_SHAPE_PROXYTYPE", CONVEX_POINT_CLOUD_SHAPE_PROXYTYPE),
            value("CUSTOM_POLYHEDRAL_SHAPE_TYPE", CUSTOM_POLYHEDRAL_SHAPE_TYPE),
            value("SPHERE_SHAPE_PROXYTYPE", SPHERE_SHAPE_PROXYTYPE),
            value("MULTI_SPHERE_SHAPE_PROXYTYPE", MULTI_SPHERE_SHAPE_PROXYTYPE),
            value("CAPSULE_SHAPE_PROXYTYPE", CAPSULE_SHAPE_PROXYTYPE),
            value("CONE_SHAPE_PROXYTYPE", CONE_SHAPE_PROXYTYPE),
            value("CONVEX_SHAPE_PROXYTYPE", CONVEX_SHAPE_PROXYTYPE),
            value("CYLINDER_SHAPE_PROXYTYPE", CYLINDER_SHAPE_PROXYTYPE),
            value("UNIFORM_SCALING_SHAPE_PROXYTYPE", UNIFORM_SCALING_SHAPE_PROXYTYPE),
            value("MINKOWSKI_SUM_SHAPE_PROXYTYPE", MINKOWSKI_SUM_SHAPE_PROXYTYPE),
            value("MINKOWSKI_DIFFERENCE_SHAPE_PROXYTYPE", MINKOWSKI_DIFFERENCE_SHAPE_PROXYTYPE),
            value("BOX_2D_SHAPE_PROXYTYPE", BOX_2D_SHAPE_PROXYTYPE),
            value("CONVEX_2D_SHAPE_PROXYTYPE", CONVEX_2D_SHAPE_PROXYTYPE),
            value("CUSTOM_CONVEX_SHAPE_TYPE", CUSTOM_CONVEX_SHAPE_TYPE),
            value("TRIANGLE_MESH_SHAPE_PROXYTYPE", TRIANGLE_MESH_SHAPE_PROXYTYPE),
            value("SCALED_TRIANGLE_MESH_SHAPE_PROXYTYPE", SCALED_TRIANGLE_MESH_SHAPE_PROXYTYPE),
            value("FAST_CONCAVE_MESH_PROXYTYPE", FAST_CONCAVE_MESH_PROXYTYPE),
            value("TERRAIN_SHAPE_PROXYTYPE", TERRAIN_SHAPE_PROXYTYPE),
            value("GIMPACT_SHAPE_PROXYTYPE", GIMPACT_SHAPE_PROXYTYPE),
            value("MULTIMATERIAL_TRIANGLE_MESH_PROXYTYPE", MULTIMATERIAL_TRIANGLE_MESH_PROXYTYPE),
            value("EMPTY_SHAPE_PROXYTYPE", EMPTY_SHAPE_PROXYTYPE),
            value("STATIC_PLANE_PROXYTYPE", STATIC_PLANE_PROXYTYPE),
            value("CUSTOM_CONCAVE_SHAPE_TYPE", CUSTOM_CONCAVE_SHAPE_TYPE),
            value("COMPOUND_SHAPE_PROXYTYPE", COMPOUND_SHAPE_PROXYTYPE),
            value("SOFTBODY_SHAPE_PROXYTYPE", SOFTBODY_SHAPE_PROXYTYPE),
            value("HFFLUID_SHAPE_PROXYTYPE", HFFLUID_SHAPE_PROXYTYPE),
            value("HFFLUID_BUOYANT_CONVEX_SHAPE_PROXYTYPE", HFFLUID_BUOYANT_CONVEX_SHAPE_PROXYTYPE),
            value("INVALID_SHAPE_PROXYTYPE", INVALID_SHAPE_PROXYTYPE),
            value("MAX_BROADPHASE_COLLISION_TYPES", MAX_BROADPHASE_COLLISION_TYPES)
	    ]
	    ;
}
