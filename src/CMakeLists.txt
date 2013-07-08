include_directories(${LUABIND_INCLUDE_DIRS} ${OPENSCENEGRAPH_INCLUDE_DIR} ${CMAKE_INSTALL_PREFIX}/include/)

add_definitions(-DLUABULLET_BUILDING)

set(SOURCES
	BindingFwd.h
	ClassInfo.cpp
	ClassInfo.h
	LuaInclude.h
	LuaInterface.h
	ModuleEntryPoint.cpp
	ModuleEntryPoint.h
)

set(OSGBULLET_BINDING
	#osgbCollision/BoundingCone.cpp
	#osgbCollision/BoundingCylinder.cpp
	#osgbCollision/Chart.cpp
	#osgbCollision/CollectVerticesVistor.cpp
	#osgbCollision/CollisionShapes.cpp
	#osgbCollision/ComputeCylinderVisitor.cpp
	#osgbCollision/ComputeShapeVisitor.cpp
	#osgbCollision/ComputeTriMeshVisitor.cpp
	#osgbCollision/GLDebugDrawer.cpp
	#osgbCollision/Utils.cpp
	#osgbCollision/Version.cpp
	#osgbCollision/VertexAggOp.cpp
	#osgbDynamics/Contraints.cpp
	
	LinearMath/btVector3.cpp
	#LinearMath/btAlignedAllocator.cpp
	
	#osgbDynamics/GroundPlane.cpp
	#osgbDynamics/MotionState.cpp
	#osgbDynamics/PhysicsState.cpp
	#osgbDynamics/PhysicsThread.cpp
	#osgbDynamics/RigidBody.cpp
	#osgbDynamics/RigidBodyAnimation.cpp
	#osgbDynamics/TripleBuffer.cpp
)

add_library(luabullet MODULE ${SOURCES} ${OSGBULLET_BINDING})
set_property(TARGET luabullet PROPERTY PREFIX "")
target_link_libraries(luabullet ${LUABIND_LIBRARIES})


install(TARGETS luabullet
	RUNTIME DESTINATION bin COMPONENT binding
	LIBRARY DESTINATION bin COMPONENT binding)

set(LUABULLET_INSTALL_NAME "${CMAKE_INSTALL_PREFIX}/bin/luabullet${CMAKE_SHARED_MODULE_SUFFIX}")

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

#http://www.cmake.org/Wiki/BundleUtilitiesExample
#install(CODE "
#  include(BundleUtilities)
#  fixup_bundle(\"${APP}\" \"${PLUGINS}\" \"${LIBRARY_DIRS}\")
#  ")
