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

#include <BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.h>
#include <LinearMath/btIDebugDraw.h>
#include <BulletCollision/BroadphaseCollision/btDispatcher.h>
#include <BulletCollision/NarrowPhaseCollision/btPersistentManifold.h>

// Standard includes
// - none



template<> luabind::scope getLuaBinding<btSequentialImpulseConstraintSolver>() {
	using namespace luabind;

	return
	    class_<btSequentialImpulseConstraintSolver, btConstraintSolver> ("btSequentialImpulseConstraintSolver")
	    .def(constructor<>())
	    .def("solveGroup", &btSequentialImpulseConstraintSolver::solveGroup)
	    .def("reset", &btSequentialImpulseConstraintSolver::reset)
	    .def("btRand2", &btSequentialImpulseConstraintSolver::btRand2)
	    .def("btRandInt2", &btSequentialImpulseConstraintSolver::btRandInt2)
	    .def("setRandSeed", &btSequentialImpulseConstraintSolver::setRandSeed)
	    .def("getRandSeed", &btSequentialImpulseConstraintSolver::getRandSeed)
	    ;
}
