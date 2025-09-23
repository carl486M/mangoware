#pragma once
#include <cstdint>

#define MANGO_VERSION_MAJOR 0
#define MANGO_VERSION_MINOR 1
#define MANGO_VERSION_MICRO 3
#define MANGO_VERSION_BRANCH "raw"
#define MANGO_VERISON_COMMIT "unknown"

class camera;
#include "types.hpp"

class engine {
    private:
        class input {
            public:
                bool keyDown(int scancode) const;
                bool mouseDown(int button) const;
                const int& keycode = keyPressed;
                void pollInputs();
                bool running = true;
                input();
            private:
                int keyPressed;
                bool key[512];
                bool mouse[3];
        };
    public:
        static engine instance(const char* title, int width, int height, uint32_t flags) {
            static engine inst(title, width, height, flags);
            return inst;
        }

        float delta() { return deltatime; }
        
        // its a timer.
        uint32_t timer();
        /*
            UPDATES AND POLL EVENTS AND CLEARS THE SCREEN
        */
        void update();
        /*
            RENDER IT!
        */
        void render();
        void setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
        input event;
        vec2 getCenter(camera* camera);


        inline bool intersects(const rect2D& a, const rect2D& b) {
            return (a.x < b.x + b.w &&
            a.x + a.w > b.x &&
            a.y < b.y + b.h &&
            a.y + a.h > b.y);
        }

        void quit();
    protected:
        float deltatime;
    private:
        vec4 clearColor;
        engine(const char* title, int width, int height, uint32_t flags);
        void init();
};
