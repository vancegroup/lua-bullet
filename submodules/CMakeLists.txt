# ------------ osgWorks ---------------------------------
# osgWorks will be built later as a submodule, so we force these variables for the time being
set(osgWorks_FOUND TRUE CACHE INTERNAL "" FORCE)

# Recurse into osgWorks
add_subdirectory(osgworks)

set(OSGWORKS_INCLUDE_DIRS
	"${CMAKE_CURRENT_SOURCE_DIR}/osgworks/include/")

# Propagate include dirs
set(OSGWORKS_INCLUDE_DIRS "${OSGWORKS_INCLUDE_DIRS}" PARENT_SCOPE)


# ------------- Bullet ----------------------------------
#http://bulletphysics.org/mediawiki-1.5.8/index.php/Installation
set(BUILD_SHARED_LIBS ON)
set(INSTALL_LIBS ON)

# Bullet will be built later as a submodule, so we force these variables for the time being
set(BULLET_DYNAMICS_LIBRARY TRUE CACHE INTERNAL "" FORCE)
set(BULLET_COLLISION_LIBRARY TRUE CACHE INTERNAL "" FORCE)
set(BULLET_MATH_LIBRARY TRUE CACHE INTERNAL "" FORCE)
set(BULLET_SOFTBODY_LIBRARY TRUE CACHE INTERNAL "" FORCE)

# Recurse into Bullet
add_subdirectory(bullet)

set(BULLET_INCLUDE_DIR
	"${CMAKE_CURRENT_SOURCE_DIR}/bullet/src/")

# Propagate include dirs
set(BULLET_INCLUDE_DIR "${BULLET_INCLUDE_DIR}" PARENT_SCOPE)


# ------------- osgBullet ----------------------------------
# Recurse into osgBullet
add_subdirectory(osgbullet)

set(OSGBULLET_INCLUDE_DIRS
	"${CMAKE_CURRENT_SOURCE_DIR}/osgbullet/include/")

# Propagate include dirs
set(OSGBULLET_INCLUDE_DIRS "${OSGBULLET_INCLUDE_DIRS}" PARENT_SCOPE)
