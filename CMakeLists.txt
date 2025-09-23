set(SDL2_VENDORED ON)
set(SDL2_DLL OFF)

cmake_minimum_required(VERSION 3.30)
project("mangoware")
cmake_policy(SET CMP0077 NEW)
message(STATUS "mangoware")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
option(SDL2_VENDORED "Use SDL2 in lib" ON)
option(SDL2_DLL "SDL2 but shared" OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)

execute_process(
    COMMAND git describe --always
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_COMMIT
    OUTPUT_STRIP_TRAILING_WHITESPACE
    RESULT_VARIABLE GIT_REV_PARSE_RESULT
)

if(NOT GIT_REV_PARSE_RESULT EQUAL 0)
    message(WARNING "Failed to get Git commit, Setting to 'unknown'.")
    set(GIT_COMMIT "unknown")
endif()

if (SDL2_VENDORED)
    message(STATUS "Using vendored SDL2")
    if (SDL2_DLL)
        set(SDL_SHARED ON)
        set(SDL_STATIC OFF)
    else()
        set(SDL_STATIC ON)
        set(SDL_SHARED OFF)
    endif (SDL2_DLL)
    set(SDL_TEST OFF)
    set(SDL_TEST_LIBRARY OFF)
    set(SDL_DISABLE_INSTALL_DOCS ON)
    set(SDL_DISABLE_INSTALL ON)
    set(SDL_LIBC ON)
    set(BUILD_SHARED_LIBS OFF)
    add_subdirectory("libs/SDL")
    # add_subdirectory("libs/SDL_TTF")
else()
    message(STATUS "Using system SDL2")
    find_package(SDL2 REQUIRED CONFIG)
endif()

set(TMXLITE_STATIC_LIB ON)

add_subdirectory("./libs/tmxlite/tmxlite")

add_library(${PROJECT_NAME} SHARED
    #I'M GUI
    "./src/imgui/imgui_draw.cpp"
    "./src/imgui/imgui_tables.cpp"
    "./src/imgui/imgui_widgets.cpp"
    "./src/imgui/imgui.cpp"
    "./src/imgui/backend/imgui_impl_sdl2.cpp"
    "./src/imgui/backend/imgui_impl_sdlrenderer2.cpp"

    "./src/system.cc"
    "./src/engine.cc"
    "./src/tilemap.cc"
    "./src/input.cc"
    "./src/sprite.cc"
    "./src/camera.cc"
)

target_compile_definitions(${PROJECT_NAME} PUBLIC MANGO_VERSION_COMMIT=${GIT_COMMIT})

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
target_link_libraries(${PROJECT_NAME} PUBLIC SDL2::SDL2 SDL2::SDL2main tmxlite)

if(WIN32 AND SDL2_DLL)
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy $<TARGET_FILE:SDL2::SDL2> $<TARGET_FILE_DIR:${PROJECT_NAME}>
        VERBATIM
    )
endif()