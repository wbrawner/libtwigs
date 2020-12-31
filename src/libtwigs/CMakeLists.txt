# Copyright © 2020 William Brawner.
#
# This file is part of Twigs
#
# Twigs is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Twigs is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Twigs  If not, see <https://www.gnu.org/licenses/>.

include(GNUInstallDirs)

set(TWIGS_INCLUDE_DIR ../../include)
set(PUBLIC_HEADERS
    ${TWIGS_INCLUDE_DIR}/twigs/twigs.h
    ${TWIGS_INCLUDE_DIR}/twigs/budget.h
    ${TWIGS_INCLUDE_DIR}/twigs/category.h
    ${TWIGS_INCLUDE_DIR}/twigs/hashable.h
    ${TWIGS_INCLUDE_DIR}/twigs/identifiable.h
    ${TWIGS_INCLUDE_DIR}/twigs/permission.h
    ${TWIGS_INCLUDE_DIR}/twigs/transaction.h
    ${TWIGS_INCLUDE_DIR}/twigs/user.h
)

set(TWIGS_SOURCES
    budget.cpp
    #category.cpp
    transaction.cpp
    #twigs.cpp
    #user.cpp
    )

#if (NOT TARGET CURL)
    #find_library(
        #CURL
        #NAMES curl libcurl
        #PATHS /usr/local/lib /usr/local/lib64 /usr/lib /usr/lib64 /lib
        #)
    #if (NOT CURL)
        #message(SEND_ERROR "Did not find curl")
    #endif()
#endif()
#if (NOT TARGET JSONC)
    #find_library(
        #JSONC
        #NAMES json-c libjson-c
        #PATHS /usr/local/lib /usr/local/lib64 /usr/lib /usr/lib64 /lib
        #)
    #if (NOT JSONC)
        #message(SEND_ERROR "Did not find json-c")
    #endif()
#endif()
#if (NOT TARGET CRYPTO)
    #find_library(
        #CRYPTO
        #NAMES crypto libcrypto
        #PATHS /usr/local/lib /usr/local/lib64 /usr/lib /usr/lib64 /lib
        #)
    #if (NOT CRYPTO)
        #message(SEND_ERROR "Did not find OpenSSL")
    #endif()
#endif()
#if (NOT TARGET OPENSSL)
    #find_library(
        #OPENSSL
        #NAMES ssl libssl
        #PATHS /usr/local/lib /usr/local/lib64 /usr/lib /usr/lib64 /lib
        #)
    #if (NOT OPENSSL)
        #message(SEND_ERROR "Did not find OpenSSL")
    #endif()
#endif()

option(TWIGS_STATIC "Build Twigs as a static library" ON)
option(TWIGS_SHARED "Build Twigs as a shared library" OFF)

if (TWIGS_STATIC)
    add_library(libtwigs SHARED
        ${TWIGS_SOURCES}
        ${PUBLIC_HEADERS}
        )
else()
    add_library(libtwigs STATIC
        ${TWIGS_SOURCES}
        ${PUBLIC_HEADERS}
        )
endif()

target_include_directories(libtwigs PRIVATE
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/${TWIGS_INCLUDE_DIR}>
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include/twigs>
)

set_target_properties(libtwigs PROPERTIES
    OUTPUT_NAME "twigs"
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    )
    
install(TARGETS libtwigs
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )

#target_link_libraries(twigs ${CURL}
    #${JSONC}
    #${CRYPTO}
    #${OPENSSL}
    #)
