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
#ifndef INCLUDED_ClassInfo_h_GUID_cd08f2ca_8e9d_477b_95af_cf006bd07b1e
#define INCLUDED_ClassInfo_h_GUID_cd08f2ca_8e9d_477b_95af_cf006bd07b1e

// Internal Includes
// - none

// Library/third-party includes
#include <luabind/lua_state_fwd.hpp>

// Standard includes
// - none

void bindClassInfo(lua_State * L);

#endif // INCLUDED_ClassInfo_h_GUID_cd08f2ca_8e9d_477b_95af_cf006bd07b1e
