add_subdirectory(libtwigs)

option(TWIGS_TESTS "Build tests for Twigs" ON)

if (TWIGS_TESTS)
    add_subdirectory(test)
endif()
