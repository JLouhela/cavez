add_library(game_interface INTERFACE)
target_include_directories (game_interface INTERFACE include)

add_library(game 
    src/game_impl.hpp
    src/game_impl.cpp
    src/game_state_impl.hpp
    src/game_state_impl.cpp
    src/components/component_container.hpp
    src/components/component_container.cpp
    src/components/component_id.hpp
    src/components/physics_component.hpp
	src/entity/entity.hpp
	src/entity/entity_container.hpp
	src/entity/entity_container.cpp)

#TODO source group components / entity
    
target_link_libraries(game
    PUBLIC
        game_interface
	PRIVATE
		logger
		math)