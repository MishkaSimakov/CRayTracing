#pragma once

#ifndef RAYTRACING_CAMERA_H
#define RAYTRACING_CAMERA_H

#include "../Math/VecFunctions.h"
#include "../Math/Mat2.h"

class Camera {
public:
    vec3 pos;
    vec3 direction;

    Camera(vec3 _pos, vec3 _direction) : pos(_pos), direction(_direction) {};

    vec3 getDirection(vec2 point, vec2 size) {
        vec3 rayDirection = vec3(point / size - 0.5, 0) - pos;

        return norm(rayDirection);
    }
};

#endif //RAYTRACING_CAMERA_H
