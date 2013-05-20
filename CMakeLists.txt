
cmake_minimum_required(VERSION 2.8.4)

# Set package properties
project(luabullet)

set(CPACK_PACKAGE_VENDOR "Iowa State University - Vance Research Group")
set(CPACK_PACKAGE_CONTACT "Ryan Pavlik <rpavlik@iastate.edu>")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(OpenSceneGraph REQUIRED)
find_package(Boost REQUIRED)
find_package(Luabind REQUIRED)
find_program(LUA_COMMAND lua lua5.1)

message(STATUS "*Tip* Set OSGInstallType to Source and Build Tree for help finding OSG")

set(BINDIR bin)
set(LIBDIR lib)
set(INCLUDEDIR include)

add_subdirectory(submodules)
add_subdirectory(src)
