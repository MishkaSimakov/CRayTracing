#pragma once

#ifndef RAYTRACING_SHAPE_H
#define RAYTRACING_SHAPE_H

#include "../math/VecFunctions.h"
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
        return mix(
                reflect_d(hit) * material->diff_k,
                reflect_m(hit, rd) * (1 - material->diff_k)
        );
    }

    vec3 reflect_m(vec3 hit, vec3 rd) {
        vec3 N = normal(hit);

        vec3 L = -rd;
        vec3 R = N * 2 * dot(N, L) - L;

        return R;
    }

    vec3 reflect_d(vec3 hit) {
        vec3 N = normal(hit);

        vec3 rand = norm(vec3(
                (std::rand() % 100) / 50 - 1,
                (std::rand() % 100) / 50 - 1,
                (std::rand() % 100) / 50 - 1
            ));

        if (dot(rand, N) < 0) return -rand;

        return rand;
    }
};

#endif //RAYTRACING_SHAPE_H
