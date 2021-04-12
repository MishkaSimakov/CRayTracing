//
// Created by msima on 11.04.2021.
//

#ifndef RAYTRACING_CHESSMATERIAL_H
#define RAYTRACING_CHESSMATERIAL_H

#include "Material.h"

class ChessMaterial : public Material {
public:
    ChessMaterial() : Material(Color(0), 0.25, 1) {}

    Color color(vec3 hit) override {
        int sum = hit.x + hit.y + hit.z;

        if (sum % 2 == 0) {
            return Color(1);
        }

        return Color(0);
    }
};

#endif //RAYTRACING_CHESSMATERIAL_H
