add_library(assets_interface INTERFACE)
target_include_directories (assets_interface INTERFACE include)

add_library(assets 
    include/assets/texture_id.hpp
    include/assets/texture_manager_interface.hpp
    src/texture_manager_impl.hpp
    src/texture_manager_impl.cpp)
    
target_link_libraries(assets
    PUBLIC
        assets_interface
	PRIVATE
		sfml-graphics)