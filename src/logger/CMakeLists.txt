add_library(logger
    include/logger/logger.hpp
    include/logger/output_interface.hpp
    src/console_output.hpp
    src/console_output.cpp
    src/logger.cpp)
    
target_include_directories(logger PUBLIC include)
