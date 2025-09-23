#include <cstdint>
#include <cstdio>
#include <mango/engine.hpp>
#include <mango.hpp>
#include "shared.h"
#include <iostream>
#include <mango/imgui/imgui.h>

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

    SDL_version compiled;
    SDL_RendererInfo info;
    SDL_GetRendererInfo(global::renderer, &info);
    SDL_GetVersion(&compiled);
    
    std::cout << "mangoware " << 
        MANGO_VERSION_MAJOR << "." <<
        MANGO_VERSION_MINOR << "." <<
        MANGO_VERSION_MICRO << "-" <<
        MANGO_VERSION_BRANCH << " (" << MANGO_VERISON_COMMIT << ")";
    printf(" (SDL %u.%u.%u with %s)\n",
       compiled.major, compiled.minor, compiled.patch, info.name);
    std::cout << mangosystem::platform() << " " << mangosystem::kernelVersion() << " [" << mangosystem::compiler() << " " << mangosystem::compilerVersion() << "/" << mangosystem::architecture() << "]\n";

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGui_ImplSDL2_InitForSDLRenderer(global::window, global::renderer);
    ImGui_ImplSDLRenderer2_Init(global::renderer);
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
    ImGui_ImplSDL2_ProcessEvent(&global::event);

    SDL_SetRenderDrawColor(global::renderer, clearColor.x, clearColor.y, clearColor.z, clearColor.w);
    SDL_RenderClear(global::renderer);
    ImGui_ImplSDLRenderer2_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
}

void engine::render() {
    ImGui::Render();
    ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), global::renderer);
    SDL_RenderPresent(global::renderer);
}

void engine::setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    clearColor = {r, g, b, a};
}  

uint32_t engine::timer() {
    return SDL_GetTicks();
}

void engine::quit() {
    // std::cout << "bye bye" << std::endl;
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    SDL_DestroyRenderer(global::renderer);
	SDL_DestroyWindow(global::window);
	SDL_Quit();
}

vec2 engine::getCenter(camera* cam) {
    int logicalW, logicalH;
    SDL_RenderGetLogicalSize(global::renderer, &logicalW, &logicalH);
    return vec2(logicalW / 2, logicalH / 2);
}