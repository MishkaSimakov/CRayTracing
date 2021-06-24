//
// Created by msima on 11.04.2021.
//

#ifndef RAYTRACING_MATERIAL_H
#define RAYTRACING_MATERIAL_H

#include "../Math/VecFunctions.h"
#include "../Color.h"

class Material {
public:
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    double reflection;

    double shininess;

    Material(vec3 _ambient, vec3 _diffuse, vec3 _specular, double _reflection, double _shininess) :
            ambient(_ambient), diffuse(_diffuse), specular(_specular), reflection(_reflection), shininess(_shininess) {}
};

#endif //RAYTRACING_MATERIAL_H
