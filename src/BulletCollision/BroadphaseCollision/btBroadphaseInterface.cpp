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

#include <BulletCollision/BroadphaseCollision/btBroadphaseInterface.h>


// Standard includes
// - none



template<> luabind::scope getLuaBinding<btBroadphaseInterface>() {
	using namespace luabind;

	return
	    class_<btBroadphaseInterface> ("btBroadphaseInterface")
		.def("createProxy", &btBroadphaseInterface::createProxy)
		.def("destroyProxy", &btBroadphaseInterface::destroyProxy)
		.def("setAabb", &btBroadphaseInterface::setAabb)
		.def("getAabb", &btBroadphaseInterface::getAabb)
		.def("rayTest", &btBroadphaseInterface::rayTest)
		.def("aabbTest", &btBroadphaseInterface::aabbTest)
		.def("calculateOverlappingPairs", &btBroadphaseInterface::calculateOverlappingPairs)
		///@todo: implement these
		//.def("getOverlappingPairCache", const)
		//.def("getOverlappingPairCache", nonconst)
		.def("getBroadphaseAabb", &btBroadphaseInterface::getBroadphaseAabb)
		.def("resetPool", &btBroadphaseInterface::resetPool)
		.def("printStats", &btBroadphaseInterface::printStats)
	    ;
}
