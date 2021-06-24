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
#include "Scene/Triangle.h"
#include "Scene/Camera.h"
#include "Scene/Light.h"
#include "Scene/Sky.h"


const int WIDTH = 2000;
const int HEIGHT = 2000;
//const int HEIGHT = (int) (WIDTH / 1920. * 1080.);

const int samples_count = 1;

const int recursion_limit = 8;
const double max_distance = 50;


// scene objects
std::vector<Shape*> shapes = {};
Light light(vec3(0, 0, 5), 5, 1);

std::string image_path = "D:/Programs/CLionProjects/Raytracing/rendered.jpg";

Camera camera(vec3(0, 0, -1), norm(vec3(1, 0, 0)));
Sky sky("D:/Programs/CLionProjects/Raytracing/assets/sky_low_r.jpg");


const int map_width = 19;
const int map_height = 15;
double height_map[map_width * map_height];

#endif //RAYTRACING_VARIABLES_H
