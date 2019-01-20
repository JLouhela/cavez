add_library(game_interface INTERFACE)
target_include_directories (game_interface INTERFACE include)

add_library(game 
	include/game/game_interface.hpp
	include/game/game_state_interface.hpp
    src/game_impl.hpp
    src/game_impl.cpp
    src/game_state_impl.hpp
    src/game_state_impl.cpp
    src/ec/component_container.hpp
    src/ec/component_id.hpp
	src/ec/entity.hpp
	src/ec/entity.cpp
	src/ec/entity_container.hpp
	src/ec/entity_container.cpp
	src/ec/entity_factory.hpp
	src/ec/entity_factory.cpp
    src/ec/static_array/static_array.hpp
    src/ec/components/physics_component.hpp
    src/ec/components/render_component.hpp
    src/systems/physics_system.hpp
    src/systems/physics_system.cpp
    src/systems/render_system.hpp
    src/systems/render_system.cpp
    src/systems/system_manager.hpp
    src/systems/system_manager.cpp
)

target_include_directories(game
	PUBLIC
		include
	PRIVATE
		src
)

#TODO source group components / entity
    
target_link_libraries(game
    PUBLIC
        game_interface
	PRIVATE
		logger
		math)