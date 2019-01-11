add_library(menu_interface INTERFACE)
target_include_directories (menu_interface INTERFACE include)

add_library(menu 
    src/menu_impl.hpp
    src/menu_impl.cpp)
    
target_link_libraries(menu
    PUBLIC
        menu_interface)