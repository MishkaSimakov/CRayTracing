#pragma once

#include <cmath>
#include "Vec3.h"

double sign(double a) { return (0 < a) - (a < 0); }
vec3 sign(vec3 v) { return vec3(sign(v.x), sign(v.y), sign(v.z)); }

double length(vec2 v) { return sqrt(v.x * v.x + v.y * v.y); }
double length(vec3 v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z); }

vec2 norm(vec2 v) { return v / length(v); }
vec3 norm(vec3 v) { return v / length(v); }

double dot(vec3 a, vec3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

vec3 abs(vec3 v) { return vec3(fabs(v.x), fabs(v.y), fabs(v.z)); }

vec3 mix(vec3 a, vec3 b) { return norm(a + b); }