add_library(math 
    include/math/bounding_box.hpp
	include/math/rect.hpp
    include/math/vector.hpp
    src/vector.cpp)
    
target_include_directories (math PUBLIC include)