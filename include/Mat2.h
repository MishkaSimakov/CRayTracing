//
// Created by msima on 11.04.2021.
//

#ifndef RAYTRACING_MAT2_H
#define RAYTRACING_MAT2_H

struct mat2 {
    double a, b, c, d;

    mat2(double _a, double _b, double _c, double _d) : a(_a), b(_b), c(_c), d(_d) {}

    vec2 operator*(vec2 other) { return vec2(other.x * a + other.y * c, other.x * b + other.y * d); }
};

#endif //RAYTRACING_MAT2_H
