

set(SOURCES

)

set(API

)



#add_library(luabullet MODULE ${SOURCES} ${API})
#set_property(TARGET luabullet PROPERTY PREFIX "")
#target_link_libraries(luabullet ${LUABIND_LIBRARIES})




#install(TARGETS luabullet
#	RUNTIME DESTINATION bin COMPONENT binding
#	LIBRARY DESTINATION bin COMPONENT binding)

#set(LUABULLET_INSTALL_NAME "${CMAKE_INSTALL_PREFIX}/bin/luabullet${CMAKE_SHARED_MODULE_SUFFIX}")

#set(APP)
#set(PLUGINS)
#set(LIBRARY_DIRS)

#if(LUA_COMMAND)
#	install(PROGRAMS "${LUA_COMMAND}" DESTINATION bin)
#	get_filename_component(LUA_COMMAND_FILENAME "${LUA_COMMAND}" NAME)
#	list(APPEND PLUGINS "${LUABULLET_INSTALL_NAME}")
#	set(APP "${CMAKE_INSTALL_PREFIX}/bin/${LUA_COMMAND_FILENAME}")
#else()
#	set(APP "${LUABULLET_INSTALL_NAME}")
#endif()


#get_filename_component(LUA_LIBDIR "${LUA_LIBRARY}" PATH)
#list(APPEND LIBRARY_DIRS "${LUA_LIBDIR}")

#install(CODE "
#  include(BundleUtilities)
#  fixup_bundle(\"${APP}\" \"${PLUGINS}\" \"${LIBRARY_DIRS}\")
#  ")
