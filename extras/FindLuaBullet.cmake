# - Find lua-bullet
#
# Users may optionally supply:
#  LUABULLET_ROOT_DIR - a prefix to start searching
#
# Non-cache variables you might use in your CMakeLists.txt:
#  LUABULLET_FOUND
#  LUABULLET_INCLUDE_DIRS
#  LUABULLET_LIBRARIES
#
# Requires these CMake modules:
#  FindPackageHandleStandardArgs (known included with CMake >=2.6.2)
#


set(LUABULLET_ROOT_DIR
	"${LUABULLET_ROOT_DIR}"
	CACHE
	PATH
	"Path to search for lua-bullet")

###
# Dependencies
###
find_package(OpenSceneGraph QUIET COMPONENTS osgGA osgText osgViewer osgSim osgDB osgShadow osgUtil osg OpenThreads)

###
# Configure Luabullet
###
find_path(LUABULLET_INCLUDE_DIR
	NAMES
	Version.h
	HINTS
	"${LUABULLET_ROOT_DIR}"
	PATH_SUFFIXES
	include)
mark_as_advanced(LUABULLET_INCLUDE_DIR)

find_library(LUABULLET_LIBRARY
	NAMES
	luabullet
	HINTS
	"${LUABULLET_ROOT_DIR}"
	PATH_SUFFIXES
	lib64
	lib)
mark_as_advanced(LUABULLET_LIBRARY)

# handle the QUIETLY and REQUIRED arguments and set xxx_FOUND to TRUE if
# all listed variables are TRUE
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(LuaBullet
	DEFAULT_MSG
	LUABULLET_LIBRARY
	LUABULLET_INCLUDE_DIR
	OPENSCENEGRAPH_LIBRARIES
	OPENSCENEGRAPH_INCLUDE_DIR)

if(LUABULLET_FOUND)
	set(LUABULLET_INCLUDE_DIRS "${LUABULLET_INCLUDE_DIR}" "${OPENSCENEGRAPH_INCLUDE_DIR}")
	set(LUABULLET_LIBRARIES "${LUABULLET_LIBRARY}" ${OPENSCENEGRAPH_LIBRARIES})
	mark_as_advanced(LUABULLET_ROOT_DIR)
endif()
