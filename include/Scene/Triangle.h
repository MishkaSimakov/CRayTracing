//
// Created by msima on 13.04.2021.
//

#ifndef RAYTRACING_TRIANGLE_H
#define RAYTRACING_TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
public:
    vec3 v1, v2, v3, triangle_normal = vec3(0);
    
    Triangle(vec3 _v1, vec3 _v2, vec3 _v3, Material *_material) : Shape(_material), v1(_v1), v2(_v2), v3(_v3) {
        triangle_normal = cross(v2 - v1, v3 - v1);
    }
    
    double intersection(vec3 ro, vec3 rd) override {
        vec3 e1 = v2 - v1;
        vec3 e2 = v3 - v1;
        // Вычисление вектора нормали к плоскости
        vec3 pvec = cross(rd, e2);
        float det = dot(e1, pvec);

        // Луч параллелен плоскости
        if (det < 1e-8 && det > -1e-8) {
            return -1;
        }

        float inv_det = 1 / det;
        vec3 tvec = ro - v1;
        float u = dot(tvec, pvec) * inv_det;
        if (u < 0 || u > 1) {
            return -1;
        }

        vec3 qvec = cross(tvec, e1);
        float v = dot(rd, qvec) * inv_det;
        if (v < 0 || u + v > 1) {
            return -1;
        }
        return dot(e2, qvec) * inv_det;
    }

    vec3 normal(vec3 hit) override {
        return triangle_normal;
    }
};

#endif //RAYTRACING_TRIANGLE_H
