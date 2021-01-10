add_subdirectory(libtwigs)

option(BUILD_TESTING "Build tests for Twigs" ON)

if (BUILD_TESTING)
    add_subdirectory(test)
endif()
