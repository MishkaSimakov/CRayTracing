#pragma once

#include "cmath"
#include "Vec3.h"

double length(vec2 v) { return sqrt(v.x * v.x + v.y * v.y); }
double length(vec3 v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z); }

vec2 norm(vec2 v) { return v / length(v); }
vec3 norm(vec3 v) { return v / length(v); }

vec3 cross(vec3 a, vec3 b) {
    return vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

double dot(vec3 a, vec3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

vec3 mix(vec3 a, vec3 b) { return norm(a + b); }