add_library(rendering_interface INTERFACE)
target_include_directories (rendering_interface INTERFACE include)
target_link_libraries(rendering_interface INTERFACE assets_interface)

add_library(rendering 
    include/rendering/rendering_interface.hpp
    include/rendering/rendering_target.hpp
	include/rendering/render_items.hpp
    src/image_renderer.hpp
    src/image_renderer.cpp
    src/rendering_impl.hpp
    src/rendering_impl.cpp)
    
target_link_libraries(rendering
	PUBLIC
        rendering_interface
		math
    PRIVATE
		logger
		game_interface
        sfml-window
        sfml-graphics)
