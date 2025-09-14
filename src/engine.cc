#include <SDL_scancode.h>
#include <cstdint>
#include <mango/engine.hpp>
#include "SDL_main.h"
#include "SDL_render.h"
#include "shared.h"

void mango::init() {
    SDL_SetMainReady();
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)  {
        std::cerr << "[ERROR] Can't init SDL2: " << SDL_GetError() << std::endl;
    }
}

mango::mango(const char *title, int width, int height, uint32_t flags) {
    init();

    global::window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
    global::renderer = SDL_CreateRenderer(global::window, -1, flags | SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_PRESENTVSYNC);
    global::event = {};

    SDL_version linkedVER;
    SDL_GetVersion(&linkedVER);
    
    std::cout << "mangoware " << 
        MANGO_VERSION_MAJOR << "." <<
        MANGO_VERSION_MINOR << "." <<
        MANGO_VERSION_MICRO << "-" <<
        MANGO_VERSION_BRANCH << " (SDL " <<
        linkedVER.major << "." << linkedVER.minor << "." << linkedVER.patch << " on " <<
        SDL_GetPlatform() << ")" << 
    std::endl;
}

void mango::update() {
    event.pollInputs();
    SDL_RenderClear(global::renderer);
}

void mango::render() {
    SDL_RenderPresent(global::renderer);
}

void mango::setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    SDL_SetRenderDrawColor(global::renderer, r, g, b, a);
}

uint32_t mango::timer() {
    return SDL_GetTicks();
}

void mango::quit() {
    std::cout << "bye bye" << std::endl;
    SDL_DestroyRenderer(global::renderer);
	SDL_DestroyWindow(global::window);
	SDL_Quit();
}