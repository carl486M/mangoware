#pragma once
#include <cstdint>

#define MANGO_VERSION_MAJOR 1
#define MANGO_VERSION_MINOR 0
#define MANGO_VERSION_MICRO 0
#define MANGO_VERSION_BRANCH "dev"

class mango {
    private:
        class input {
            public:
                bool keyDown(int scancode) const;
                bool mouseDown(int button) const;
                void pollInputs();
                input();
            private:
                bool key[512];
                bool mouse[3];
        };
    public:
        static mango instance(const char* title, int width, int height, uint32_t flags) {
            static mango inst(title, width, height, flags);
            return inst;
        }

        void update();
        void render();
        void setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
        input event;

        ~mango() { quit(); }
    private:
        mango(const char* title, int width, int height, uint32_t flags);
        void init();
        void quit();
};

struct vec2 {
    int x, y;
    vec2(int x, int y) : x(x), y(y) {}
};

struct vec3 {
    int x, y, z;
    vec3(int x, int y, int z) : x(x), y(y), z(z) {}
};