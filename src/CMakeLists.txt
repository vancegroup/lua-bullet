#Put some checks in here so we know the variables have a value
#http://www.cmake.org/cmake/help/v2.8.11/cmake.html#command:message
if("${LUABIND_INCLUDE_DIRS}" STREQUAL "")
	message(FATAL_ERROR "LUABIND_INCLUDE_DIRS is empty.")
endif()
if("${OPENSCENEGRAPH_INCLUDE_DIR}" STREQUAL "")
	message(FATAL_ERROR "OPENSCENEGRAPH_INCLUDE_DIR is empty.")
endif()

include_directories(${LUABIND_INCLUDE_DIRS}
	${OPENSCENEGRAPH_INCLUDE_DIR}
	"${OSGWORKS_INSTALL_DIR}/include"
	"${BULLET_INSTALL_DIR}/include/bullet"
	"${OSGBULLET_INSTALL_DIR}/include"
	${Boost_INCLUDE_DIRS}
	${OSGLUA_INCLUDE_DIRS})

add_definitions(-DLUABULLET_BUILDING)


#list(APPEND CMAKE_PREFIX_PATH "${CMAKE_INSTALL_PREFIX}/lib/")
#find_package(Bullet REQUIRED)

#Add FindOSGWorks.cmake file
#list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/submodules/osgworks/extra/")
#find_package(osgWorks REQUIRED)

#Add FindOSGBullet.cmake file
#list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/submodules/osgbullet/extra/")
#find_package(osgBullet REQUIRED)


set(SOURCES
	BindingFwd.h
	ClassInfo.cpp
	ClassInfo.h
	LuaInclude.h
	LuaInterface.h
	ModuleEntryPoint.cpp
	ModuleEntryPoint.h
	Version.h
)

set(OSGBULLET_BINDING
	#Bullet:
	LinearMath/btVector3.cpp
	BulletCollision/CollisionShapes/btCollisionShape.cpp
	BulletCollision/CollisionShapes/btBoxShape.cpp
	BulletCollision/CollisionShapes/btTriangleMeshShape.cpp
	BulletCollision/CollisionShapes/btStridingMeshInterface.cpp
	BulletCollision/CollisionShapes/btPolyhedralConvexShape.cpp
	BulletCollision/CollisionShapes/btConvexInternalShape.cpp
	BulletCollision/CollisionShapes/btConvexShape.cpp
	BulletCollision/CollisionShapes/btConcaveShape.cpp
	BulletCollision/CollisionShapes/btStaticPlaneShape.cpp
	BulletCollision/CollisionShapes/btSphereShape.cpp
	BulletCollision/CollisionShapes/btCylinderShape.cpp
	BulletCollision/CollisionShapes/btConvexTriangleMeshShape.cpp
	BulletCollision/Gimpact/btGImpactCollisionAlgorithm.cpp
	BulletDynamics/Dynamics/btRigidBody.cpp
	BulletDynamics/ConstraintSolver/btConstraintSolver.cpp
	BulletCollision/CollisionDispatch/btDefaultCollisionConfiguration.cpp
	BulletCollision/CollisionDispatch/btCollisionDispatcher.cpp
	BulletCollision/CollisionDispatch/btCollisionWorld.cpp
	BulletCollision/CollisionDispatch/btActivatingCollisionAlgorithm.cpp
	BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.cpp
	BulletCollision/BroadphaseCollision/btAxisSweep3.cpp
	BulletCollision/BroadphaseCollision/btBroadphaseInterface.cpp
	BulletCollision/BroadphaseCollision/btCollisionAlgorithm.cpp
	BulletCollision/BroadphaseCollision/btDbvtBroadphase.cpp
	BulletDynamics/Dynamics/btDiscreteDynamicsWorld.cpp
	BulletDynamics/Dynamics/btDynamicsWorld.cpp
	LinearMath/btTransform.cpp
	LinearMath/btMotionState.cpp
	LinearMath/btQuadWord.cpp
	LinearMath/btQuaternion.cpp
	BulletCollision/BroadphaseCollision/btBroadphaseProxy.cpp
	BulletCollision/BroadphaseCollision/btDispatcher.cpp
	BulletCollision/CollisionShapes/btCompoundShape.cpp
	BulletCollision/CollisionDispatch/btCollisionObject.cpp
	
	#osgBullet:
	osgbDynamics/MotionState.cpp
	osgbDynamics/PhysicsThread.cpp
	osgbDynamics/PhysicsState.cpp
	osgbDynamics/PhysicsData.cpp
	osgbDynamics/RigidBody.cpp
	osgbCollision/ComputeShapeVisitor.cpp
	osgbCollision/ComputeTriMeshVisitor.cpp
	osgbCollision/CollectVerticesVisitor.cpp
	osgbCollision/ComputeCylinderVisitor.cpp
	osgbCollision/CollisionShapes.cpp
	osgbCollision/CollisionShapes.h
)

add_library(luabullet MODULE ${SOURCES} ${OSGBULLET_BINDING})
set_property(TARGET luabullet PROPERTY PREFIX "")

# Handle linking against shared libraries on Linux and Windows.
if(CMAKE_LINK_LIBRARY_SUFFIX)
	set(SHARED_LIBRARY_SUFFIX ${CMAKE_LINK_LIBRARY_SUFFIX})
else()
	set(SHARED_LIBRARY_SUFFIX ${CMAKE_SHARED_LIBRARY_SUFFIX})
endif()

target_link_libraries(luabullet
	${LUA_LIBRARIES}
	${LUABIND_LIBRARIES}
	${OPENSCENEGRAPH_LIBRARIES}
	${OSGLUA_LIBRARIES}
	"${BULLET_INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}BulletCollision${CMAKE_STATIC_LIBRARY_SUFFIX}"
	"${BULLET_INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}BulletDynamics${CMAKE_STATIC_LIBRARY_SUFFIX}"
	"${BULLET_INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}LinearMath${CMAKE_STATIC_LIBRARY_SUFFIX}"
	"${BULLET_INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}BulletSoftBody${CMAKE_STATIC_LIBRARY_SUFFIX}"
	"${OSGBULLET_INSTALL_DIR}/lib/${CMAKE_SHARED_LIBRARY_PREFIX}osgbCollision${SHARED_LIBRARY_SUFFIX}"
	"${OSGBULLET_INSTALL_DIR}/lib/${CMAKE_SHARED_LIBRARY_PREFIX}osgbDynamics${SHARED_LIBRARY_SUFFIX}"
	"${OSGWORKS_INSTALL_DIR}/lib/${CMAKE_SHARED_LIBRARY_PREFIX}osgwTools${SHARED_LIBRARY_SUFFIX}")

add_dependencies(luabullet osgBullet)

#http://www.cmake.org/cmake/help/v2.8.11/cmake.html#command:install
install(TARGETS luabullet
	RUNTIME DESTINATION bin COMPONENT binding
	LIBRARY DESTINATION lib COMPONENT binding)

set(LUABULLET_INSTALL_NAME "${CMAKE_INSTALL_PREFIX}/bin/${CMAKE_SHARED_LIBRARY_PREFIX}luabullet${CMAKE_SHARED_MODULE_SUFFIX}")

set(APP)
set(PLUGINS)
set(LIBRARY_DIRS)

if(LUA_COMMAND)
	install(PROGRAMS "${LUA_COMMAND}" DESTINATION bin)
	get_filename_component(LUA_COMMAND_FILENAME "${LUA_COMMAND}" NAME)
	list(APPEND PLUGINS "${LUABULLET_INSTALL_NAME}")
	set(APP "${CMAKE_INSTALL_PREFIX}/bin/${LUA_COMMAND_FILENAME}")
else()
	set(APP "${LUABULLET_INSTALL_NAME}")
endif()


get_filename_component(LUA_LIBDIR "${LUA_LIBRARY}" PATH)
list(APPEND LIBRARY_DIRS "${LUA_LIBDIR}")

# Copy over Version.h header into install location
#file(COPY "${PROJECT_SOURCE_DIR}/src/Version.h" DESTINATION "${CMAKE_INSTALL_PREFIX}/include/")


#For OSX:
#http://www.cmake.org/Wiki/BundleUtilitiesExample
#install(CODE "
#  include(BundleUtilities)
#  fixup_bundle(\"${APP}\" \"${PLUGINS}\" \"${LIBRARY_DIRS}\")
#  ")
