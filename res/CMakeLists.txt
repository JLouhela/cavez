configure_file(res_path.hpp.in res_path.hpp)

target_include_directories(assets PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
