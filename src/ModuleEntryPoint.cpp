/**
	@file
	@brief Implementation

	@date 2013

	@author
	Ryan Pavlik
	<rpavlik@iastate.edu> and <abiryan@ryand.net>
	http://academic.cleardefinition.com/
	Iowa State University Virtual Reality Applications Center
	Human-Computer Interaction Graduate Program
*/

//          Copyright Iowa State University 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


// Internal Includes
#include "ModuleEntryPoint.h"
#include "BindingFwd.h"
#include "ClassInfo.h"


// Library/third-party includes
#include <luabind/open.hpp>


// Standard includes
// - none

namespace LinearMath {
	class btVector3;
	class btAlignedAllocator;
}

int luaopen_luabullet(lua_State *L) {
	using namespace luabind;
	open(L);
	//http://www.lua.org/manual/5.1/manual.html#5.3
	module(L, "LinearMath")
	[	
	    getLuaBinding<LinearMath::btVector3>(),


	    scope() // trailing empty scope so we can put commas after each binding call
	];
	bindClassInfo(L);
	return 0;
}
