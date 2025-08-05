#include "shared.h"
#include <mango/engine.hpp>

mango::input::input() {
    for (int i = 0; i < 512; ++i) {
        key[i] = false;
    }
    for (int i = 0; i < 3; ++i) {
        mouse[i] = false;
    }
}

bool mango::input::keyDown(int scancode) const {
    return key[scancode];
}
    
bool mango::input::mouseDown(int button) const {
    return mouse[button];
}
void mango::input::pollInputs() {
    SDL_PollEvent(&global::event);

    if (global::event.type == SDL_QUIT) {
        running = false;// simulate escape
    }
    for (int i = 0; i < 512; ++i) {
        key[i] = SDL_GetKeyboardState(NULL)[i];
    }
    mouse[0] = SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT);
    mouse[1] = SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT);
    mouse[2] = SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_MIDDLE);

    if (global::event.type == SDL_KEYDOWN) {
        key[global::event.key.keysym.scancode] = true;
        input::keyPressed = global::event.key.keysym.scancode;
    } else if (global::event.type == SDL_KEYUP) {
        key[global::event.key.keysym.scancode] = false;
        input::keyPressed = false;
    }
    if (global::event.type == SDL_MOUSEBUTTONDOWN) {
        if (global::event.button.button < 3) {
            mouse[global::event.button.button] = true;
        }
    } else if (global::event.type == SDL_MOUSEBUTTONUP) {
        if (global::event.button.button < 3) {
            mouse[global::event.button.button] = false;
        }
    }
}