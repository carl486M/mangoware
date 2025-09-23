#pragma once
#include "mango/types.hpp"
#include <SDL2/SDL.h>
#include <cstdint>
#include <tmxlite/Map.hpp>
#include <tmxlite/TileLayer.hpp>
#include <string>

class camera;

class tilemap {
    public:
        tilemap(camera* cam);
        ~tilemap();
        bool load(const std::string& tilemap, const std::string& tilesheet, int tilesize);
        void render();
        const std::vector<rect2D>& getCollision() const;
    private:
        camera* _camera;
        void buildCollision(const std::string& collisionLayerName);
        SDL_Texture* _tilesheet;
        tmx::Map _map;
        const tmx::Tileset* findTilesetForGID(unsigned gid) const;
        int _tileSize;
        int _spacing, _margin;
        std::vector<rect2D> _collisions;
        SDL_Rect getTileSRC(std::uint32_t gid);
};