add_executable (SandboxApp src/sandbox_main.cpp)

target_link_libraries(SandboxApp
PRIVATE
    sfml-system
    sfml-window
)