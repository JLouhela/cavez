add_library(input_interface INTERFACE)
target_include_directories (input_interface INTERFACE include)

add_library(input 
	include/input/input_interface.hpp
	include/input/input_key.hpp
	include/input/input_mapping.hpp
	include/input/input_state.hpp
    src/input_impl.hpp
    src/input_impl.cpp)
    
target_link_libraries(input
    PUBLIC
        input_interface
	PRIVATE
		sfml-window)