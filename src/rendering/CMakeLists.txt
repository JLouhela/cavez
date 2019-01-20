add_library(rendering_interface INTERFACE)
target_include_directories (rendering_interface INTERFACE include)

add_library(rendering 
    include/rendering/rendering_interface.hpp
	include/rendering/render_items.hpp
    src/rendering_impl.hpp
    src/rendering_impl.cpp)
    
target_link_libraries(rendering
	PUBLIC
        rendering_interface
		assets_interface
		math
    PRIVATE
		logger
		game_interface
        sfml-window
        sfml-graphics)