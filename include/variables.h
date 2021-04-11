#pragma once

#ifndef RAYTRACING_VARIABLES_H
#define RAYTRACING_VARIABLES_H

#include "vector"
#include "string"

#include "Materials/Material.h"
#include "Materials/ChessMaterial.h"

#include "Scene/Sphere.h"
#include "Scene/Plane.h"
#include "Scene/Camera.h"
#include "Scene/Light.h"


const int w = 500;
const int h = w / 1920. * 1080.;

const int recursion_limit = 10;
const double max_distance = 999;

const bool save_to_image = false;
const std::string path = "D:/Programs/CLionProjects/Raytracing/rendered.jpg";

// scene objects
std::vector<Shape*> shapes = {};
std::vector<Light*> lights = {};

Camera camera(vec3(-10, 0, -5), vec3(0));

Color sky_color(0.01, 0.86, 1.0);

#endif //RAYTRACING_VARIABLES_H
