#pragma once
#include <SDL2/SDL.h>
#include <iostream>

namespace global {
    inline SDL_Window* window = nullptr;
    inline SDL_Renderer* renderer = nullptr;
    inline SDL_Event event = {};
}