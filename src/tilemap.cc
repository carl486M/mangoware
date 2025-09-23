#include <iostream>
#include <mango/tilemap.hpp>
#include "mango/camera.hpp"
#include "shared.h"

tilemap::tilemap(camera* cam) : _tilesheet(nullptr), _tileSize(0), _camera(cam) {}
tilemap::~tilemap() { if (_tilesheet) SDL_DestroyTexture(_tilesheet); }

bool tilemap::load(const std::string& tilemap, const std::string& tilesheet, int tilesize) {
    if (!_map.load(tilemap)) {
        std::cerr << "[ERROR] Failed to load map: " << tilemap << std::endl;
        return false;
    } 

    _tileSize = tilesize;

    SDL_Surface* surface = SDL_LoadBMP(tilesheet.c_str());
    if (!surface) {
        std::cerr << "Failed to load tilesheet: " << tilesheet << " because " << SDL_GetError() << std::endl;
        return false;
    }

    _tilesheet = SDL_CreateTextureFromSurface(global::renderer, surface);
    if (!_tilesheet) {
        std::cerr << "Failed to make texture because " << SDL_GetError() << std::endl;
        return false;
    }

    if (!_map.getTilesets().empty()) {
        const auto& ts = _map.getTilesets()[0];
        _spacing = ts.getSpacing();
        _margin = ts.getMargin();
    } else {
        _spacing = 0;
        _margin = 0;
    }

    buildCollision("collisions");
    return true;
}

void tilemap::buildCollision(const std::string& collisionLayerName) {
    _collisions.clear();

    // find the collision layer
    const tmx::Layer* layer = nullptr;
    for (const auto& l : _map.getLayers()) {
        if (l->getType() == tmx::Layer::Type::Tile && l->getName() == collisionLayerName) {
            layer = l.get();
            break;
        }
    }
    if (!layer) {
        SDL_Log("Collision layer '%s' not found!", collisionLayerName.c_str());
        return;
    }

    const auto& tileLayer = layer->getLayerAs<tmx::TileLayer>();

    const auto& chunks = tileLayer.getChunks();
    if (!chunks.empty()) {
        for (const auto& chunk : chunks) {
            unsigned int chunkWidth  = chunk.size.x;
            unsigned int chunkHeight = chunk.size.y;

            for (unsigned int y = 0; y < chunkHeight; ++y) {
                for (unsigned int x = 0; x < chunkWidth; ++x) {
                    auto gid = chunk.tiles[y * chunkWidth + x].ID;
                    if (gid == 0) continue; // empty tile = no collision

                    // compute world pos
                    int worldX = (chunk.position.x + x) * _tileSize;
                    int worldY = (chunk.position.y + y) * _tileSize;

                    rect2D rect;
                    rect.x = worldX;
                    rect.y = worldY;
                    rect.w = _tileSize;
                    rect.h = _tileSize;

                    _collisions.push_back(rect);
                }
            }
        }
    } else {
        // non-infinite map fallback
        const auto& tiles = tileLayer.getTiles();
        const auto& size = tileLayer.getSize();

        for (unsigned int y = 0; y < size.y; ++y) {
            for (unsigned int x = 0; x < size.x; ++x) {
                auto gid = tiles[y * size.x + x].ID;
                if (gid == 0) continue;

                rect2D rect;
                rect.x = x * _tileSize;
                rect.y = y * _tileSize;
                rect.w = _tileSize;
                rect.h = _tileSize;

                _collisions.push_back(rect);
            }
        }
    }
}

SDL_Rect tilemap::getTileSRC(std::uint32_t gid) {
    const auto& tilesets = _map.getTilesets();
    if (tilesets.empty()) return {0, 0, 0, 0};

    auto firstGID = tilesets[0].getFirstGID();
    auto columns = tilesets[0].getColumnCount();

    std::uint32_t id = gid - firstGID;

    SDL_Rect src;
    src.x = _margin + (id % columns) * (_tileSize + _spacing);
    src.y = _margin + (id / columns) * (_tileSize + _spacing);
    src.w = _tileSize;
    src.h = _tileSize;

    return src;
}
void tilemap::render() {
    for (const auto& layer : _map.getLayers()) {
        if (layer->getType() != tmx::Layer::Type::Tile) continue;
        const auto& tileLayer = layer->getLayerAs<tmx::TileLayer>();
        const auto& chunks = tileLayer.getChunks();

        // ✅ Infinite map (chunks exist)
        if (!chunks.empty()) {
            for (const auto& chunk : chunks) {
                unsigned int chunkWidth  = chunk.size.x;
                unsigned int chunkHeight = chunk.size.y;

                // World bounds of this chunk (not offset by camera yet)
                int chunkLeft   = chunk.position.x * _tileSize;
                int chunkTop    = chunk.position.y * _tileSize;
                int chunkRight  = chunkLeft + chunkWidth * _tileSize;
                int chunkBottom = chunkTop + chunkHeight * _tileSize;

                // Skip chunks not visible in camera
                if (chunkRight  < _camera->view.x || chunkLeft > _camera->view.x + _camera->view.w ||
                    chunkBottom < _camera->view.y || chunkTop  > _camera->view.y + _camera->view.h) continue;

                for (unsigned int y = 0; y < chunkHeight; ++y) {
                    for (unsigned int x = 0; x < chunkWidth; ++x) {
                        auto gid = chunk.tiles[y * chunkWidth + x].ID;
                        if (gid == 0) continue;

                        // ✅ World position (0,0 = top-left of map)
                        int worldX = (chunk.position.x + x) * _tileSize;
                        int worldY = (chunk.position.y + y) * _tileSize;

                        SDL_Rect src = getTileSRC(gid);

                        // ✅ Convert world -> screen space with camera
                        SDL_Rect dest = {
                            worldX - _camera->view.x,
                            worldY - _camera->view.y,
                            _tileSize, _tileSize
                        };

                        SDL_RenderCopy(global::renderer, _tilesheet, &src, &dest);
                    }
                }
            }
        } 
        // ✅ Finite map (no chunks)
        else {
            const auto& tiles = tileLayer.getTiles();
            const auto& size = tileLayer.getSize();

            for (unsigned int y = 0; y < size.y; ++y) {
                for (unsigned int x = 0; x < size.x; ++x) {
                    auto gid = tiles[y * size.x + x].ID;
                    if (gid == 0) continue;

                    // ✅ World position (0,0 = top-left of map)
                    int worldX = x * _tileSize;
                    int worldY = y * _tileSize;

                    // Cull offscreen tiles
                    if (worldX + _tileSize < _camera->view.x || worldX > _camera->view.x + _camera->view.w ||
                        worldY + _tileSize < _camera->view.y || worldY > _camera->view.y + _camera->view.h) continue;

                    SDL_Rect src = getTileSRC(gid);

                    // ✅ Convert world -> screen space
                    SDL_Rect dest = {
                        worldX - _camera->view.x,
                        worldY - _camera->view.y,
                        _tileSize, _tileSize
                    };

                    SDL_RenderCopy(global::renderer, _tilesheet, &src, &dest);
                }
            }
        }
    }

    SDL_SetRenderDrawColor(global::renderer, 255, 0, 0, 100);
    for (const auto& coll : _collisions) {
        SDL_Rect r{
            coll.x - _camera->view.x,
            coll.y - _camera->view.y,
            coll.w,
            coll.h
        };
        SDL_RenderDrawRect(global::renderer, &r);
    }
}


const std::vector<rect2D>& tilemap::getCollision() const{
    return _collisions;
}