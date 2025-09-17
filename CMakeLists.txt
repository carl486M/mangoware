set(SDL2_VENDORED ON)
cmake_minimum_required(VERSION 3.30)
project("mangoware")
cmake_policy(SET CMP0077 NEW)
message(STATUS "mangoware")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
option(SDL2_VENDORED "Use SDL2 in lib" ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)

if (SDL2_VENDORED)
    message(STATUS "Using vendored SDL2")
    set(SDL_SHARED OFF)
    set(SDL_STATIC ON)
    set(SDL_TEST OFF)
    set(SDL_TEST_LIBRARY OFF)
    set(SDL_DISABLE_INSTALL_DOCS ON)
    set(SDL_DISABLE_INSTALL ON)
    set(SDL_LIBC ON)
    set(BUILD_SHARED_LIBS OFF)
    add_subdirectory("libs/SDL")
    add_subdirectory("libs/SDL_TTF")
else()
    message(STATUS "Using system SDL2")
    find_package(SDL2 REQUIRED CONFIG)
endif()

add_library(${PROJECT_NAME} SHARED
    "./src/engine.cc"
    "./src/input.cc"
    "./src/sprite.cc"
    "./src/camera.cc"
)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(${PROJECT_NAME} PUBLIC SDL2::SDL2-static SDL2_ttf SDL2::SDL2main)