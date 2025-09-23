#pragma once
#include <cstdint>

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;
typedef int8_t sint8;
typedef int16_t sint16;
typedef int32_t sint32;
typedef int64_t sint64;

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
    // rect2D(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}
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

namespace mangosystem  {
    const char* platform();
    const char* compiler();
    const char* architecture();
    const char* compilerVersion();
    const char* kernelVersion();
}