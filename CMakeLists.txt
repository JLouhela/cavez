# CMakeLists files in this project can
# refer to the root source directory of the project as ${CAVEZ_SOURCE_DIR} and
# to the root binary directory of the project as ${CAVEZ_BINARY_DIR}.
cmake_minimum_required (VERSION 3.9.0)
project (Cavez VERSION 0.0.1 LANGUAGES CXX)

# Preparations for switching to shared libs and manually copying the libs to binary folder
# SFML_ROOT not effectively used for anything currently
set(SFML_ROOT "SFML_ROOT_NOT_SET" CACHE STRING "File path pointing to SFML 2.5.1 root folder")
set(SFML_DIR ${SFML_ROOT}/lib/cmake/SFML)

if (${SFML_ROOT} MATCHES "SFML_ROOT_NOT_SET")
    message( FATAL_ERROR "SFML root folder not defined, CMake will exit." )
endif (${SFML_ROOT} MATCHES "SFML_ROOT_NOT_SET")

#TODO switch to shared libs - painful with visual studio, let's live with static for now
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

add_subdirectory (src)
