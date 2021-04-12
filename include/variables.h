#pragma once

#ifndef RAYTRACING_VARIABLES_H
#define RAYTRACING_VARIABLES_H

#include "vector"
#include "string"
#include "iostream"

#include "Materials/Material.h"
#include "Materials/ChessMaterial.h"

#include "Scene/Sphere.h"
#include "Scene/Plane.h"
#include "Scene/Camera.h"
#include "Scene/Light.h"
#include "Scene/Sky.h"


const int WIDTH = 1920 * 5;
const int HEIGHT = (int) (WIDTH / 1920. * 1080.);

const int samples = 10;

const int recursion_limit = 5;
const double max_distance = 100;

const bool save_to_image = true;


// scene objects
std::vector<Shape*> shapes = {};
std::vector<Light*> lights = {};

std::string image_path = "D:/Programs/CLionProjects/Raytracing/rendered.jpg";

Camera camera(vec3(-10, 0, -5), norm(vec3(1, 0, 0)));
Sky sky("D:/Programs/CLionProjects/Raytracing/assets/sky_low_r.jpg");

#endif //RAYTRACING_VARIABLES_H
