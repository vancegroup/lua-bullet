# ------------ osgWorks ---------------------------------
# osgWorks will be built later as a submodule, so we force these variables for the time being
set(osgWorks_FOUND TRUE CACHE INTERNAL "" FORCE)

# Recurse into osgWorks
add_subdirectory(osgworks)

set(OSGWORKS_INCLUDE_DIRS
	"${CMAKE_CURRENT_SOURCE_DIR}/osgworks/include/")

# Propagate include dirs
set(OSGWORKS_INCLUDE_DIRS "${OSGWORKS_INCLUDE_DIRS}" PARENT_SCOPE)

include_directories(${OSGWORKS_INCLUDE_DIRS} "${CMAKE_CURRENT_SOURCE_DIR}/osgworks/src/}")


# ------------- Bullet ----------------------------------
#http://bulletphysics.org/mediawiki-1.5.8/index.php/Installation
set(BUILD_SHARED_LIBS ON)
set(INSTALL_LIBS ON)

# Bullet will be built later as a submodule, so we force these variables for the time being
set(BULLET_DYNAMICS_LIBRARY TRUE CACHE INTERNAL "" FORCE)
set(BULLET_COLLISION_LIBRARY TRUE CACHE INTERNAL "" FORCE)
set(BULLET_MATH_LIBRARY TRUE CACHE INTERNAL "" FORCE)
set(BULLET_SOFTBODY_LIBRARY TRUE CACHE INTERNAL "" FORCE)
# Don't build bullet demos
set(BUILD_DEMOS FALSE CACHE INTERNAL "" FORCE)
set(BUILD_CPU_DEMOS FALSE CACHE INTERNAL "" FORCE)

# Recurse into Bullet
add_subdirectory(bullet)

set(BULLET_INCLUDE_DIR
	"${CMAKE_CURRENT_SOURCE_DIR}/bullet/src/")

# Propagate include dirs
set(BULLET_INCLUDE_DIR "${BULLET_INCLUDE_DIR}" PARENT_SCOPE)

include_directories(${BULLET_INCLUDE_DIR} "${CMAKE_CURRENT_SOURCE_DIR}/bullet/src/}")


# ------------- osgBullet ----------------------------------
# Add in the dependencies of Bullet and osgWorks so that we can compile
#set(BulletInstallType "Source And Build Tree" CACHE INTERNAL "" FORCE)
#set(BulletBuildRoot "${CMAKE_BINARY_DIR}/submodules/bullet/" CACHE INTERNAL "" FORCE)
#set(osgWorks_DIR "${CMAKE_BINARY_DIR}/submodules/osgworks/lib/" CACHE INTERNAL "" FORCE)
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}/submodules/bullet/lib")
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}/submodules/osgworks/lib/")

# Don't build osgBullet examples
set(OSGBULLET_BUILD_EXAMPLES FALSE CACHE INTERNAL "" FORCE)

# Recurse into osgBullet
add_subdirectory(osgbullet)

set(OSGBULLET_INCLUDE_DIRS
	"${CMAKE_CURRENT_SOURCE_DIR}/osgbullet/include/")

# Propagate include dirs
set(OSGBULLET_INCLUDE_DIRS "${OSGBULLET_INCLUDE_DIRS}" PARENT_SCOPE)

include_directories(${OSGBULLET_INCLUDE_DIRS} "${CMAKE_CURRENT_SOURCE_DIR}/osgbullet/src/}")

