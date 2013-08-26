
cmake_minimum_required(VERSION 2.8.5)

# Set package properties
project(luabullet)

set(CPACK_PACKAGE_VENDOR "Iowa State University - Vance Research Group")
set(CPACK_PACKAGE_CONTACT "Ryan Pavlik <rpavlik@iastate.edu>")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(OpenSceneGraph REQUIRED COMPONENTS osgGA osgText osgViewer osgSim osgDB osgShadow osgUtil osg OpenThreads)
find_package(Boost REQUIRED)
find_package(Luabind REQUIRED)
find_program(LUA_COMMAND vrjlua lua lua5.1)

include(GNUInstallDirs)
include(CTest)

add_subdirectory(submodules) #dependencies (osgWorks, Bullet, osgBullet)

add_subdirectory(src)

if(BUILD_TESTING)
	add_subdirectory(tests)
endif()
