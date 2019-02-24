set(MATH_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/math/bounding_box.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/math/rect.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/math/vector.hpp)

add_library(math INTERFACE)
    
target_sources(math INTERFACE $<BUILD_INTERFACE:${MATH_FILES}>)
target_include_directories(math INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>)

