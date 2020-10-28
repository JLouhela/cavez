add_subdirectory(googletest-download)

add_executable(test_game test_game.cpp)
target_link_libraries(test_game gtest_main)
add_test(NAME test_game COMMAND test_game)
