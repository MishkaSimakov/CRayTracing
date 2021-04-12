//
// Created by msima on 11.04.2021.
//

#ifndef RAYTRACING_MATERIAL_H
#define RAYTRACING_MATERIAL_H

#include "../math/VecFunctions.h"
#include "../Color.h"

class Material {
public:
    double albedo;
    double diff_k;
    Color col;

    Material(Color _col, double _albedo, double _diff_k) : col(_col), albedo(_albedo), diff_k(_diff_k) {}

    virtual Color color(vec3 hit) {
        return col;
    }
};

#endif //RAYTRACING_MATERIAL_H
