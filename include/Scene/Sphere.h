#pragma once

#ifndef RAYTRACING_SPHERE_H
#define RAYTRACING_SPHERE_H

#include "Shape.h"

class Sphere : public Shape {
public:
    double radius; // square of radius
    vec3 pos;

    Sphere(vec3 _pos, double _radius, Material *_material) : Shape(_material), pos(_pos), radius(_radius * _radius) {};

    double intersection(vec3 ro, vec3 rd) override {
        vec3 oc = ro - pos;
        double b = dot(oc, rd);
        double h = b * b - dot(oc, oc) + radius;

        if (h < 0.0) return -1.0; // no intersection
        h = sqrt(h);

        return -b - h;
    }

    vec3 normal(vec3 hit) override {
        return norm(hit - pos);
    }
};

#endif //RAYTRACING_SPHERE_H
