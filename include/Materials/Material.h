//
// Created by msima on 11.04.2021.
//

#ifndef RAYTRACING_MATERIAL_H
#define RAYTRACING_MATERIAL_H

#include "../VecFunctions.h"
#include "../Color.h"

class Material {
public:
    double albedo;
    Color col;

    Material(Color _col, double _albedo) : col(_col), albedo(_albedo) {}

    virtual Color color(vec3 hit) {
        return col;
    }
};

#endif //RAYTRACING_MATERIAL_H
