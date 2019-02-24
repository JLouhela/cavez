add_library(math 
    include/math/angle_utils.hpp
    include/math/bounding_box.hpp
	include/math/rect.hpp
    include/math/vector.hpp
    src/angle_utils.cpp
)

target_include_directories(math
    PUBLIC
        include
    PRIVATE
        src
)