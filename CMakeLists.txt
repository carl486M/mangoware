cmake_minimum_required(VERSION 3.30)
project("subatomic")
message(STATUS "mangoware")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
option(SDL2_VENDORED "Use SDL2 in lib" OFF)

if (SDL2_VENDORED)
    message(STATUS "Using vendored SDL2")
    set(SDL_SHARED OFF)
    set(SDL_STATIC ON)
    set(SDL_TEST OFF)
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