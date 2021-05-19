set(TWIGS_INCLUDE_DIR ../../include)

set(TEST_SOURCES
    budget_test.cpp
    transaction_test.cpp
    utils_test.cpp
)

enable_testing()

find_package(GTest REQUIRED)

include(GoogleTest)
    
add_executable(twigs_test ${TEST_SOURCES})
    
target_link_libraries(twigs_test libtwigs GTest::GTest GTest::Main)

gtest_discover_tests(twigs_test)

set_target_properties(twigs_test PROPERTIES
    OUTPUT_NAME "twigstest"
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    )
