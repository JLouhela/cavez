add_executable (sandbox_app src/sandbox_main.cpp)

target_link_libraries(sandbox_app
PRIVATE
	rendering
	game
)