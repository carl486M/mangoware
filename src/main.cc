#include "shared.h"
#include <iostream>
#include <mango/sprite.hpp>
#ifdef __linux__
#include <SDL2/SDL.h>
#elif defined(_WIN32)
#include <SDL.h>
#endif


int main(int argc, char **argv){
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cerr << "SDL_Init failed: " << SDL_GetError() << "\n";
		return 1;
	}

	global::window = SDL_CreateWindow("no", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, 854, 480, SDL_WINDOW_RESIZABLE);
	global::renderer = SDL_CreateRenderer(global::window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_PRESENTVSYNC);

	global::event = {};
	sprite mario("./assets/mario.bmp", 16, 32);
	bool running = true;
	SDL_SetRenderDrawColor(global::renderer, 250, 167, 100, 255);
	mario.setPosition(vec2(0, 0));

	while (running) {
		
		SDL_PollEvent(&global::event);
		if (global::event.type == SDL_QUIT || global::event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
			running = false;
		}

		const Uint8 *state = SDL_GetKeyboardState(NULL);
		if (state[SDL_SCANCODE_RIGHT]) {
			mario.x += 1;
		}
		if (state[SDL_SCANCODE_LEFT]) {
			mario.x -= 1;
		}
		if (state[SDL_SCANCODE_UP]) {
			mario.y -= 1;
		}
		if (state[SDL_SCANCODE_DOWN]) {
			mario.y += 1;
		}
		if (state[SDL_SCANCODE_D]) {
			mario.angle += 1;
		}
		if (state[SDL_SCANCODE_A]) {
			mario.angle -= 1;
		}
		if (state[SDL_SCANCODE_W]) {
			mario.size += 1;
		}
		if (state[SDL_SCANCODE_S]) {
			mario.size -= 1;
		}

		SDL_RenderClear(global::renderer);

		mario.render(vec2(mario.x, mario.y), mario.angle, mario.size);

		SDL_RenderPresent(global::renderer);
	}


	// SDL_DestroyTexture(bmpTex);
	SDL_DestroyRenderer(global::renderer);
	SDL_DestroyWindow(global::window);
	SDL_Quit();
	return 0;
}