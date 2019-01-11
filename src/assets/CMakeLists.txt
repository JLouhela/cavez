add_library(assets_interface INTERFACE)
target_include_directories (assets_interface INTERFACE include)

add_library(assets 
    src/assets_impl.hpp
    src/assets_impl.cpp)
    
target_link_libraries(assets
    PUBLIC
        assets_interface)