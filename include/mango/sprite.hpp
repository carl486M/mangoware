#pragma once
#include "mango/types.hpp"
#include <SDL2/SDL.h>
class camera; // forward-declare to avoid header dependency
#include "engine.hpp"

class sprite {
    public:
        sprite(const char* path, int width, int height, camera* camera);
        void changeTile(int columm, int row);
        void pickTilefrom(vec2 pos);
        int x, y;
        int cameraX, cameraY;
        rangeInt size = {0, 0, 256};
        float angle = 0.0f;
        bool flip = false;

        bool collided(sprite* other);
        bool collided(rect2D* other);

        void setPosition(vec2 pos);
        void setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
        void render(vec2 pos, float angle, float size);
        void render();

        vec2 dimensions() { return vec2(width, height); }
        rect2D getRect() { return spriteRect; }

        ~sprite();
    private:
        camera* targetCam;
        SDL_Texture* spriteTexture;
        SDL_Rect tileset;
        rect2D spriteRect;
        int width, height;
        int texW, texH;
};