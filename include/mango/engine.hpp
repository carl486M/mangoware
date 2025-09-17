#pragma once
#include <cstdint>

#define MANGO_VERSION_MAJOR 0
#define MANGO_VERSION_MINOR 1
#define MANGO_VERSION_MICRO 2
#define MANGO_VERSION_BRANCH "dev"

class camera;

struct vec2 {
    int x, y;
    vec2(int x, int y) : x(x), y(y) {}
};

struct vec3 {
    int x, y, z;
    vec3(int x, int y, int z) : x(x), y(y), z(z) {}
};

struct vec4 {
    int x, y, z, w;
    vec4(int x, int y, int z, int w) : x(x), y(y), z(z), w(w) {} 
};

struct rect2D {
    int x, y, w, h;
    rect2D(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}
};

struct rangeInt {
private:
    int maxValue;
    int minValue;
    int value;
public:
    rangeInt(int starter, int min, int max) {
        maxValue = max;
        minValue = min; 
        if (starter < minValue || starter > maxValue) {
            starter = minValue;
        } else {
            starter = value;
        }
    }

    void set(int newvalue) {
        if (newvalue < minValue || newvalue > maxValue) {
            value = minValue;
        } else {
            value = newvalue;
        }
    }

    int get() { return value; }
};

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

        ~engine() { quit(); }
    protected:
        float deltatime;
    private:
        vec4 clearColor;
        engine(const char* title, int width, int height, uint32_t flags);
        void init();
        void quit();
};
