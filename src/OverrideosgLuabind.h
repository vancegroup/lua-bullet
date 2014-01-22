/** @file
	@brief Header

	@date 2014

	@author
	Ryan Pavlik
	<rpavlik@iastate.edu> and <abiryan@ryand.net>
	http://academic.cleardefinition.com/
	Iowa State University Virtual Reality Applications Center
	Human-Computer Interaction Graduate Program
	
*/

//           Copyright Iowa State University 2014.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef INCLUDED_OverrideosgLuabind_h_GUID_C17F2407_6627_4FBB_D1D5_3F7A4319B893
#define INCLUDED_OverrideosgLuabind_h_GUID_C17F2407_6627_4FBB_D1D5_3F7A4319B893


// Internal Includes
// - none

// Library/third-party includes
#include <luabind/class.hpp>
#include <osgLua/osgLuabind>

// Standard includes
// - none

namespace osgbDynamics {
	struct CreationRecord;
}

namespace osgLuabind {
    template<> struct Blacklist<osgbDynamics::CreationRecord> : boost::true_type {};
}

#endif // INCLUDED_OverrideosgLuabind_h_GUID_C17F2407_6627_4FBB_D1D5_3F7A4319B893

