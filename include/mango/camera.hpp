#pragma once
#include "engine.hpp"
#include <SDL2/SDL.h>

class camera {
    public:
        rect2D view;
        camera(int x, int y, int w, int h);

        void move(int dx, int dy);
        void clamp(const rect2D& worldBounds);
        void begin();
        void end();
        void follow(const rect2D& target, const rect2D& worldBounds);
        void render();

        rect2D worldToCamera(const rect2D& worldPos) {
            rect2D r = {
                worldPos.x - view.x,
                worldPos.y - view.y,
                worldPos.w,
                worldPos.h
            };

            return r;
        }
    private:
        SDL_Texture* renderTarget;
        int width, height;
};