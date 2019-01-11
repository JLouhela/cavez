add_library(messaging_interface INTERFACE)
target_include_directories (messaging_interface INTERFACE include)

add_library(messaging 
    src/messaging_impl.hpp
    src/messaging_impl.cpp)
    
target_link_libraries(messaging
    PUBLIC
        messaging_interface)