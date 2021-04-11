#pragma once
#include "Vec2.h"

struct vec3
{
    double x, y, z;

    vec3(double _value) : x(_value), y(_value), z(_value) {};
    vec3(vec2 v, double _z) : x(v.x), y(v.y), z(_z) {};
    vec3(double _x, vec2 v) : x(_x), y(v.x), z(v.y) {};
    vec3(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {};

    vec3 operator+(vec3 other) { return vec3(x + other.x, y + other.y, z + other.z); }
    vec3 operator-(vec3 other) { return vec3(x - other.x, y - other.y, z - other.z); }
    vec3 operator*(vec3 other) { return vec3(x * other.x, y * other.y, z * other.z); }
    vec3 operator/(vec3 other) { return vec3(x / other.x, y / other.y, z / other.z); }

    vec3 operator-() { return vec3(-x, -y, -z); }

    bool operator!=(vec3 other) { return x != other.x or y != other.y or z != other.z; }
};