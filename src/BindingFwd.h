/** @file
	@brief Forward declaration header for templated lua binding function

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
#ifndef INCLUDED_BindingFwd_h_GUID_fe617b29_8694_462f_866d_76c72adadf0e
#define INCLUDED_BindingFwd_h_GUID_fe617b29_8694_462f_866d_76c72adadf0e

// Internal Includes
// - none

// Library/third-party includes
#include <luabind/scope.hpp>

// Standard includes
// - none

template<typename T>
luabind::scope getLuaBinding();

#endif // INCLUDED_BindingFwd_h_GUID_fe617b29_8694_462f_866d_76c72adadf0e
