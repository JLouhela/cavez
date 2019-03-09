add_library(game_interface INTERFACE)
target_include_directories (game_interface INTERFACE include)

set(GAME_FILES
	include/game/game_interface.hpp
	include/game/game_state_interface.hpp
    src/game_impl.hpp
    src/game_impl.cpp
    src/game_state_impl.hpp
    src/game_state_impl.cpp
    src/camera/camera.hpp
    src/camera/camera.cpp
    src/camera/cameras.hpp
    src/ec/component_container.hpp
    src/ec/component_id.hpp
	src/ec/entity.hpp
	src/ec/entity.cpp
	src/ec/entity_container.hpp
	src/ec/entity_container.cpp
	src/ec/entity_factory.hpp
	src/ec/entity_factory.cpp
    src/ec/static_array/static_array.hpp
    src/ec/components/input_component.hpp
    src/ec/components/physics_component.hpp
    src/ec/components/render_component.hpp
    src/ec/components/throttle_component.hpp
    src/systems/input_system.hpp
    src/systems/input_system.cpp
    src/systems/physics_system.hpp
    src/systems/physics_system.cpp
    src/systems/render_system.hpp
    src/systems/render_system.cpp
    src/systems/system_manager.hpp
    src/systems/system_manager.cpp
    src/systems/throttle_system.hpp
    src/systems/throttle_system.cpp)

# copipasta from https://gist.github.com/Corralx/d44a7696aa06d594605f
foreach(FILE ${GAME_FILES}) 
  get_filename_component(PARENT_DIR "${FILE}" PATH)

  string(REPLACE "/" "\\" GROUP "${PARENT_DIR}")

  if ("${FILE}" MATCHES ".*\\.cpp")
    set(GROUP "Source Files\\${GROUP}")
  elseif("${FILE}" MATCHES ".*\\.hpp")
    set(GROUP "Header Files\\${GROUP}")
  endif()

  source_group("${GROUP}" FILES "${FILE}")
endforeach()


add_library(game 
	${GAME_FILES}
)

target_include_directories(game
	PUBLIC
		include
	PRIVATE
		src
)

target_link_libraries(game
    PUBLIC
        game_interface
	PRIVATE
        input_interface
		logger
		math
		rendering_interface)