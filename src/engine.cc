#include <cstdint>
#include <mango/engine.hpp>
#include "SDL_timer.h"
#include "mango/camera.hpp"
#include "shared.h"
#include <iostream>

void engine::init() {
    SDL_SetMainReady();
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)  {
        std::cerr << "[ERROR] Can't init SDL2: " << SDL_GetError() << std::endl;
    }
}

engine::engine(const char *title, int width, int height, uint32_t flags) 
: clearColor(0xFF, 0xFF, 0xFF, 0xFF) // explicitly initialize clearColor
{
    init();

    global::window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);
    global::renderer = SDL_CreateRenderer(global::window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_PRESENTVSYNC);
    global::event = {};
    SDL_version linkedVER;
    SDL_VERSION(&linkedVER);
    
    std::cout << "engineware " << 
        MANGO_VERSION_MAJOR << "." <<
        MANGO_VERSION_MINOR << "." <<
        MANGO_VERSION_MICRO << "-" <<
        MANGO_VERSION_BRANCH << " (SDL " <<
        linkedVER.major << "." << linkedVER.minor << "." << linkedVER.patch << " on " <<
        SDL_GetPlatform() << ")" << 
    std::endl;
}

float getDeltaTime() {
    static Uint64 lastTime = 0; // remembers last frame
    Uint64 now = SDL_GetPerformanceCounter();

    // First frame fix
    if (lastTime == 0) {
        lastTime = now;
        return 0.0f; // nothing has elapsed yet
    }

    float dt = (float)(now - lastTime) / SDL_GetPerformanceFrequency();
    lastTime = now;
    return dt;
}

void engine::update() {
    deltatime = getDeltaTime();
    event.pollInputs();
    SDL_SetRenderDrawColor(global::renderer, clearColor.x, clearColor.y, clearColor.z, clearColor.w);
    SDL_RenderClear(global::renderer);
}

void engine::render() {
    SDL_RenderPresent(global::renderer);
}

void engine::setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    clearColor = {r, g, b, a};
}  

uint32_t engine::timer() {
    return SDL_GetTicks();
}

void engine::quit() {
    std::cout << "bye bye" << std::endl;
    SDL_DestroyRenderer(global::renderer);
	SDL_DestroyWindow(global::window);
	SDL_Quit();
}

vec2 engine::getCenter(camera* cam) {
    int logicalW, logicalH;
    SDL_RenderGetLogicalSize(global::renderer, &logicalW, &logicalH);
    return vec2(logicalW / 2, logicalH / 2);
}