#pragma once

#ifndef RAYTRACING_PLANE_H
#define RAYTRACING_PLANE_H

class Plane : public Shape {
public:
    vec3 planeNormal;
    double D;

    Plane(double _D, vec3 _normal, Material *_material) : Shape(_material), planeNormal(_normal), D(_D) {};

    double intersection(vec3 ro, vec3 rd) override {
        double d = dot(rd, planeNormal);

        if (d >= 0) return -1;

        return -(dot(ro, planeNormal) + D) / d;
    }

    vec3 normal(vec3 hit) override {
        return planeNormal;
    }
};

#endif //RAYTRACING_PLANE_H
