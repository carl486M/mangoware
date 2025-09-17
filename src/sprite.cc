#include <mango/sprite.hpp>
#include "SDL_rect.h"
#include "SDL_render.h"
#include "shared.h"
#include <iostream>
#include <mango/camera.hpp>

sprite::sprite(const char* path, int width, int height, camera* camera)
    : width(width), height(height), spriteRect{0, 0, width, height}, targetCam(camera) {
    SDL_Surface* loaded = SDL_LoadBMP_RW(SDL_RWFromFile(path, "rb"), 1);
    if (!loaded) std::cerr << "Can't load surface: " << SDL_GetError() << std::endl;
    spriteTexture = SDL_CreateTextureFromSurface(global::renderer, loaded);
    tileset = {0, 0, width, height};
    SDL_FreeSurface(loaded);
    // std::cout << sprite::width << sprite::height << std::endl;
}

void sprite::changeTile(int columm, int row) {
    tileset.x = width * columm;
    tileset.y = height * row;
}

void sprite::pickTilefrom(vec2 pos) {
    tileset.x = pos.x;
    tileset.y = pos.y;
}

void sprite::render() {
    spriteRect = {x, y, static_cast<int>(width * size.get()), static_cast<int>(height * size.get())};
    SDL_Rect projection = convertRect2DToSDLRect(targetCam->worldToCamera(spriteRect));
    SDL_RenderCopyEx(global::renderer, sprite::spriteTexture, &tileset, &projection, 0, NULL, (SDL_RendererFlip)flip);
}

void sprite::render(vec2 pos, float angle, float size) {
    sprite::size.set(size);
    spriteRect = {pos.x, pos.y, static_cast<int>(sprite::size.get() * width), static_cast<int>(sprite::size.get() * height)};
    SDL_Rect sdlRect = convertRect2DToSDLRect(targetCam->worldToCamera(spriteRect));
    SDL_RenderCopyEx(global::renderer, spriteTexture, &tileset, &sdlRect, angle, NULL, (SDL_RendererFlip)flip);
}


void sprite::setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    SDL_SetTextureColorMod(spriteTexture, r, g, b);
    SDL_SetTextureAlphaMod(spriteTexture, a);
}

void sprite::setPosition(vec2 pos) {
    sprite::x = pos.x;
    sprite::y = pos.y;
}

bool sprite::collided(sprite* other) {
    SDL_Rect rect1 = convertRect2DToSDLRect(spriteRect);
    SDL_Rect rect2 = convertRect2DToSDLRect(other->spriteRect);
    if (SDL_HasIntersection(&rect1, &rect2)) {
        return true;
    } else {
        return false;
    }
}

sprite::~sprite() {
    std::cout << "[SPRITE] bye bye\n";
    SDL_DestroyTexture(spriteTexture);
}