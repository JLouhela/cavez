# CMakeLists files in this project can
# refer to the root source directory of the project as ${CAVEZ_SOURCE_DIR} and
# to the root binary directory of the project as ${CAVEZ_BINARY_DIR}.
cmake_minimum_required (VERSION 3.9.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project (Cavez VERSION 0.0.1 LANGUAGES CXX)

set(SFML_DIR "SFML_DIR_NOT_SET" CACHE STRING "")

if (${SFML_DIR} MATCHES "SFML_DIR_NOT_SET")
    message( FATAL_ERROR "SFML_DIR not defined, CMake will exit." )
endif (${SFML_DIR} MATCHES "SFML_DIR_NOT_SET")

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

add_subdirectory(src)
add_subdirectory(app)
