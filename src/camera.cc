#include <mango/camera.hpp>
#include "SDL_pixels.h"
#include "SDL_render.h"
#include "mango/engine.hpp"
#include "shared.h"

camera::camera(int x, int y, int w, int h) {
    renderTarget = SDL_CreateTexture(global::renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, w, h);
    view = {x, y, w, h};
}

void camera::move(int dx, int dy) {
    view.x += dx;
    view.y += dy;
}

void camera::clamp(const rect2D& worldBounds) {
        if (view.x < worldBounds.x) view.x = worldBounds.x;
        if (view.y < worldBounds.y) view.y = worldBounds.y;
        if (view.x + view.w > worldBounds.x + worldBounds.w)
            view.x = worldBounds.x + worldBounds.w - view.w;
        if (view.y + view.h > worldBounds.y + worldBounds.h)
            view.y = worldBounds.y + worldBounds.h - view.h;
}

void camera::follow(const rect2D& target, const rect2D& worldBounds) {
        // Center camera on target
        view.x = target.x + target.w / 2 - width / 2;
        view.y = target.y + target.h / 2 - height / 2;

        // Make sure we don’t go outside the world
        clamp(worldBounds);
}

void camera::begin() {
    SDL_SetRenderTarget(global::renderer, renderTarget);
    SDL_RenderClear(global::renderer);
}

void camera::end() {
    SDL_SetRenderTarget(global::renderer, NULL);
}

void camera::render() {
    SDL_RenderCopy(global::renderer, renderTarget, nullptr, nullptr);
}