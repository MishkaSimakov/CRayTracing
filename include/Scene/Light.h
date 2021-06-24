//
// Created by msima on 10.04.2021.
//

#ifndef RAYTRACING_LIGHT_H
#define RAYTRACING_LIGHT_H

class Light {
public:
    vec3 pos;
    double intensity;
    double radius;

    Light(vec3 _pos, double _intensity, double _radius) : pos(_pos), intensity(_intensity), radius(_radius * _radius) {}

    double intersection(vec3 ro, vec3 rd) {
        vec3 oc = ro - pos;
        double b = dot(oc, rd);
        double h = b * b - dot(oc, oc) + radius;

        if (h < 0.0) return -1.0; // no intersection
        return 1.0;
    }
};

#endif //RAYTRACING_LIGHT_H
