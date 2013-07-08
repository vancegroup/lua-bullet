/** @file
	@brief Header

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


#pragma once
#ifndef INCLUDED_ModuleEntryPoint_h_GUID_8690c734_bdd8_65f8_8401_87c948f4090c
#define INCLUDED_ModuleEntryPoint_h_GUID_8690c734_bdd8_65f8_8401_87c948f4090c

// Internal Includes
#include "LuaInterface.h"

// Library/third-party includes
// - none

// Standard includes
// - none

LUABULLET_BEGIN_LUA_INTERFACE

struct lua_State;
int LUABULLET_API luaopen_luabullet(lua_State *L);

LUABULLET_END_LUA_INTERFACE

#endif // INCLUDED_ModuleEntryPoint_h_GUID_8690c734_bdd8_65f8_8401_87c948f4090c
