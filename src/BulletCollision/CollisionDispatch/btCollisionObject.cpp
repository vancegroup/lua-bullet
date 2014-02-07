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

#include <BulletCollision/CollisionDispatch/btCollisionObject.h>

// Standard includes
// - none


template<> luabind::scope getLuaBinding<btCollisionObject>() {
	using namespace luabind;

	return
		class_<btCollisionObject>("btCollisionObject")
		//http://www.rasterbar.com/products/luabind/docs.html#enums
	    //add binding for various enums
		//see btCollisionObject.h for defines
	    .enum_("btCollisionObjectDefines")
	    [
            value("ACTIVE_TAG", ACTIVE_TAG),
			value("ISLAND_SLEEPING", ISLAND_SLEEPING),
			value("WANTS_DEACTIVATION", WANTS_DEACTIVATION),
			value("DISABLE_DEACTIVATION", DISABLE_DEACTIVATION),
			value("DISABLE_SIMULATION", DISABLE_SIMULATION)
		]
		.enum_("CollisionFlags")
		[
			value("CF_STATIC_OBJECT", btCollisionObject::CF_STATIC_OBJECT),
			value("CF_KINEMATIC_OBJECT", btCollisionObject::CF_KINEMATIC_OBJECT),
			value("CF_NO_CONTACT_RESPONSE", btCollisionObject::CF_NO_CONTACT_RESPONSE),
			value("CF_CUSTOM_MATERIAL_CALLBACK", btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK),
			value("CF_CHARACTER_OBJECT", btCollisionObject::CF_CHARACTER_OBJECT),
			value("CF_DISABLE_VISUALIZE_OBJECT", btCollisionObject::CF_DISABLE_VISUALIZE_OBJECT),
			value("CF_DISABLE_SPU_COLLISION_PROCESSING", btCollisionObject::CF_DISABLE_SPU_COLLISION_PROCESSING)
		]
		.enum_("CollisionObjectTypes")
		[
			value("CO_COLLISION_OBJECT", btCollisionObject::CO_COLLISION_OBJECT),
			value("CO_RIGID_BODY", btCollisionObject::CO_RIGID_BODY),
			value("CO_GHOST_OBJECT", btCollisionObject::CO_GHOST_OBJECT),
			value("CO_SOFT_BODY", btCollisionObject::CO_SOFT_BODY),
			value("CO_HF_FLUID", btCollisionObject::CO_HF_FLUID),
			value("CO_USER_TYPE", btCollisionObject::CO_USER_TYPE),
			value("CO_FEATHERSTONE_LINK", btCollisionObject::CO_FEATHERSTONE_LINK)
		]
		.enum_("AnisotropicFrictionFlags")
		[
			value("CF_ANISOTROPIC_FRICTION_DISABLED", btCollisionObject::CF_ANISOTROPIC_FRICTION_DISABLED),
			value("CF_ANISOTROPIC_FRICTION", btCollisionObject::CF_ANISOTROPIC_FRICTION),
			value("CF_ANISOTROPIC_ROLLING_FRICTION", btCollisionObject::CF_ANISOTROPIC_ROLLING_FRICTION)
		]
		.def("getCollisionFlags", &btCollisionObject::getCollisionFlags)
		.def("setCollisionFlags", &btCollisionObject::setCollisionFlags)
		.def("setActivationState", &btCollisionObject::setActivationState)
		.def("getActivationState", &btCollisionObject::getActivationState)
		;
}
