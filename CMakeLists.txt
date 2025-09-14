set(SDL2_VENDORED ON)
cmake_minimum_required(VERSION 3.30)
project("subatomic")
cmake_policy(SET CMP0077 NEW)
message(STATUS "mangoware")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
option(SDL2_VENDORED "Use SDL2 in lib" ON)

if (SDL2_VENDORED)
    message(STATUS "Using vendored SDL2")
    set(SDL_SHARED ON)
    set(SDL_STATIC OFF)
    set(SDL_TEST OFF)
    set(SDL_TEST_LIBRARY OFF)
    set(SDL_DISABLE_INSTALL_DOCS)
    set(SDL_DISABLE_INSTALL)
    set(SDL_LIBC ON)

    add_subdirectory("libs/SDL")
else()
    message(STATUS "Using system SDL2")
    find_package(SDL2 REQUIRED CONFIG)
endif()

add_executable(${PROJECT_NAME}
    "./src/engine.cc"
    "./src/input.cc"
    "./src/sprite.cc"
    "./src/main.cc"
)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(${PROJECT_NAME} PUBLIC SDL2::SDL2)

if(WIN32)
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy $<TARGET_FILE:SDL2::SDL2> $<TARGET_FILE_DIR:${PROJECT_NAME}>
        VERBATIM
    )
endif()