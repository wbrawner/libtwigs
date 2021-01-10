set(TWIGS_INCLUDE_DIR ../../include)

set(TEST_SOURCES
    main.cpp
    budget_test.h
    budget_test.cpp
    transaction_test.h
    transaction_test.cpp
    utils_test.h
    utils_test.cpp
)

find_library(CPPUNIT cppunit)
    
add_executable(twigs_test ${TEST_SOURCES})
    
target_link_libraries(twigs_test libtwigs ${CPPUNIT})
        
set_target_properties(twigs_test PROPERTIES
    OUTPUT_NAME "twigstest"
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    )

add_test(NAME twigs_test
    COMMAND ${CMAKE_CROSSCOMPILING_EMULATOR} $<TARGET_FILE:twigs_test>
)

add_custom_command(TARGET twigs_test
    POST_BUILD
    COMMAND ${CMAKE_CROSSCOMPILING_EMULATOR} $<TARGET_FILE:twigs_test>
    )
