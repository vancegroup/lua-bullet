set(LUA_TESTS
	createVector)
	
foreach(test ${LUA_TESTS})
	add_test(NAME
        run_${test}
       # WORKING_DIRECTORY 
        COMMAND
        "${CMAKE_COMMAND}" -E chdir "$<TARGET_FILE_DIR:luabullet>" "${LUA_COMMAND}"
        -l luabullet
        "${CMAKE_CURRENT_SOURCE_DIR}/${test}.lua")

endforeach()
