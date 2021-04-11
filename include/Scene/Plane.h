#pragma once

#ifndef RAYTRACING_PLANE_H
#define RAYTRACING_PLANE_H

class Plane : public Shape {
public:
    vec3 n;

    Plane(vec3 _pos, vec3 _normal, Material *_material) : Shape(_pos, _material), n(_normal) {};

    double intersection(vec3 ro, vec3 rd) override {
        return -(dot(ro, n) + pos.z) / dot(rd, n);
    }

    vec3 normal(vec3 hit) override {
        return n;
    }
};

#endif //RAYTRACING_PLANE_H
