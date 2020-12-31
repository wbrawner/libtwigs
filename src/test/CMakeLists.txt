set(TWIGS_INCLUDE_DIR ../../include)

set(TEST_SOURCES
    main.cpp
    budget_test.h
    budget_test.cpp
    transaction_test.h
    transaction_test.cpp
)

find_library(CPPUNIT cppunit)
    
add_executable(twigs_test
    ${TEST_SOURCES}
    ${PUBLIC_HEADERS}
)
    
target_link_libraries(twigs_test libtwigs ${CPPUNIT})
    
target_include_directories(twigs_test PRIVATE
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/${TWIGS_INCLUDE_DIR}>
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include/twigs>
)

message("CMAKE_INSTALL_INCLUDEDIR: ${CMAKE_INSTALL_INCLUDEDIR}")
message("CMAKE_CURRENT_LIST_DIR}/TWIGS_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/${TWIGS_INCLUDE_DIR}")
message("PROJECT_BINARY_DIR/include/twigs: ${PROJECT_BINARY_DIR}/include/twigs}")

set_target_properties(twigs_test PROPERTIES
    OUTPUT_NAME "twigstest"
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    )
