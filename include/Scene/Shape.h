#pragma once

#ifndef RAYTRACING_SHAPE_H
#define RAYTRACING_SHAPE_H

#include "../VecFunctions.h"
#include "SFML/Graphics.hpp"
#include "../Color.h"
#include "../Materials/Material.h"

class Shape {
public:
    vec3 pos;
    Material *material;

    Shape(vec3 _pos, Material *_material) : pos(_pos), material(_material) {};

    virtual double intersection(vec3 ro, vec3 rd) {};
    virtual vec3 normal(vec3 hit) {};

    void move(vec3 offset) {
        pos = pos + offset;
    }
    vec3 reflect(vec3 hit, vec3 rd) {
        vec3 N = normal(hit);

        vec3 L = -rd;
        vec3 R = N * 2 * dot(N, L) - L;

        return R;
    }
};

#endif //RAYTRACING_SHAPE_H
