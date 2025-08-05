#include <mango/sprite.hpp>
#include "shared.h"
#include <iostream>

sprite::sprite(const char* path, int width, int height) : width(width), height(height) {
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
    SDL_Rect destRect = {x, y, width * size, height * size};
    SDL_RenderCopy(global::renderer, sprite::spriteTexture, &tileset, &destRect);
}

void sprite::render(vec2 pos, float angle, int size) {
    SDL_Rect destRect = {pos.x, pos.y, size * width, size * height};
    SDL_RenderCopyEx(global::renderer, spriteTexture, &tileset, &destRect, angle, NULL, SDL_FLIP_NONE);
}

void sprite::setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    SDL_SetTextureColorMod(spriteTexture, r, g, b);
    SDL_SetTextureAlphaMod(spriteTexture, a);
}

void sprite::setPosition(vec2 pos) {
    sprite::x = pos.x;
    sprite::y = pos.y;
}

sprite::~sprite() {
    std::cout << "[SPRITE] bye bye\n";
    SDL_DestroyTexture(spriteTexture);
}