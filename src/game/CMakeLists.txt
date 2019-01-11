add_library(game_interface INTERFACE)
target_include_directories (game_interface INTERFACE include)

add_library(game 
    src/game_impl.hpp
    src/game_impl.cpp)
    
target_link_libraries(game
    PUBLIC
        game_interface)