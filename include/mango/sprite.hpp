#pragma once
#include <SDL2/SDL.h>
#include "engine.hpp"
class sprite {
    public:
        sprite(const char* path, int width, int height);
        void changeTile(int columm, int row);
        void pickTilefrom(vec2 pos);
        int x, y;
        int size = 1;
        float angle;

        void setPosition(vec2 pos);
        void setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
        void render(vec2 pos, float angle, int size);
        void render();
        ~sprite();
    private:
        SDL_Texture* spriteTexture;
        SDL_Rect tileset;
        int width, height;
        int texW, texH;
};