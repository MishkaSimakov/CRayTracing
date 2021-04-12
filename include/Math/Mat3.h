//
// Created by msima on 12.04.2021.
//

#ifndef RAYTRACING_MAT3_H
#define RAYTRACING_MAT3_H

struct Mat3 {
    vec3 a, b, c;

    Mat3(vec3 _a, vec3 _b, vec3 _c) : a(_a), b(_b), c(_c) {}

    vec3 operator*(vec3 other) {
        return vec3(
            dot(a, other),
            dot(b, other),
            dot(c, other)
        );
    }
};

#endif //RAYTRACING_MAT3_H
