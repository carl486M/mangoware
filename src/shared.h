#pragma once
#include <SDL2/SDL.h>
#include <mango/engine.hpp>
#include "imgui/backend/imgui_impl_sdl2.h"
#include "imgui/backend/imgui_impl_sdlrenderer2.h"

namespace global {
    inline SDL_Window* window = nullptr;
    inline SDL_Renderer* renderer = nullptr;
    inline SDL_Event event = {};
}

inline rect2D convertSDLRectToRect2D(const SDL_Rect& sdlRect) {
    return rect2D{sdlRect.x, sdlRect.y, sdlRect.w, sdlRect.h};
}

inline SDL_Rect convertRect2DToSDLRect(const rect2D& rect) {
    return SDL_Rect{rect.x, rect.y, rect.w, rect.h};
}