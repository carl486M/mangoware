#pragma once
#include "camera.hpp"
#include <memory>

class scene {
    public:
        virtual ~scene() {}
        camera cam;
        void onInit() { };
        void onExit() { }
        virtual void update(float dt) = 0;
        virtual void render() = 0;
};

class sceneMGR {
    public:
        void changeScene(std::unique_ptr<scene> newScene);
        void handleEvents();
        void update();
        void render();
};