#pragma once

#ifndef RAYTRACING_SHAPE_H
#define RAYTRACING_SHAPE_H

#include "../Math/VecFunctions.h"
#include "../Materials/Material.h"

class Shape {
public:
    Material *material;

    Shape(Material *_material) : material(_material) {}

    virtual double intersection(vec3 ro, vec3 rd) {
        return -1.0;
    }

    virtual vec3 normal(vec3 hit) {
        return norm(-hit);
    }

    vec3 reflect(vec3 hit, vec3 rd) {
//        return mix(
//                reflect_d(hit) * material->diff_k,
//                reflect_m(hit, rd) * (1 - material->diff_k)
//        );

        return reflect_m(hit, rd);
    }

    vec3 reflect_m(vec3 hit, vec3 rd) {
        vec3 N = normal(hit);

        vec3 L = -rd;
        vec3 R = N * 2 * dot(N, L) - L;

        return R;
    }

    vec3 reflect_d(vec3 hit) {
        vec3 N = normal(hit);

        double theta = std::rand() % 629 / 100; // random in [0, two_pi]
        double v = std::rand() % 1001 / 1000; // random in [0, 1]
        double phi = acos((2 * v) - 1);

        double a = std::rand() % 1001 / 1000;
        double r = pow(a, 1/3);
        double x = r * sin(phi) * cos(theta);
        double y = r * sin(phi) * sin(theta);
        double z = r * cos(phi);

        vec3 rand = vec3(x, y, z);

        if (dot(rand, N) < 0) return -rand;

        return rand;
    }
};

#endif //RAYTRACING_SHAPE_H
