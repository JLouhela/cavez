add_library(hud_interface INTERFACE)
target_include_directories (hud_interface INTERFACE include)

add_library(hud 
    src/hud_impl.hpp
    src/hud_impl.cpp)
    
target_link_libraries(hud
    PUBLIC
        hud_interface)