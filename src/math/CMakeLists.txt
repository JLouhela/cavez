add_library(math 
    include/math/vector.hpp
    src/vector.cpp)
    
target_include_directories (math PUBLIC include)