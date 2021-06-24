#pragma once

#ifndef RAYTRACING_GRAPHICSMANAGER_H
#define RAYTRACING_GRAPHICSMANAGER_H

#include "variables.h"
#include "thread"

struct intersectionInfo {
    double distance;
    Shape *shape;

    intersectionInfo(double _distance, Shape *_shape) : distance(_distance), shape(_shape) {};
};


class GraphicsManager {
public:
    int width, height;

    GraphicsManager(int _width, int _height)
            : width(_width),
              height(_height) {};

    auto draw(int samples) {
        auto pixels = new sf::Uint8[WIDTH * HEIGHT * 3];

        vec2 size(WIDTH, HEIGHT);

        vec3 ro(0);
        vec3 rd(0);
        vec3 color(0);

        int pos;

        std::vector<std::thread> threads;

        std::cout << "Start rendering..." << std::endl;

        for (int sample = 0; sample < samples; ++sample) {
            for (int x = 0; x < WIDTH; ++x) {
                for (int y = 0; y < HEIGHT; ++y) {
                    ro = camera.pos;
                    rd = camera.getDirection(vec2(x, y), size);

                    color = castRay(ro, rd) * 255;

                    vec3 new_col = vec3(
                            (color.x > 255) ? 255 : color.x,
                            (color.y > 255) ? 255 : color.y,
                            (color.z > 255) ? 255 : color.z
                    );

                    pos = (y * WIDTH + x) * 3;
                    pixels[pos] = (unsigned int) ((new_col.x + pixels[pos] * sample) / (sample + 1));
                    pixels[pos + 1] = (unsigned int) ((new_col.y + pixels[pos + 1] * sample) / (sample + 1));
                    pixels[pos + 2] = (unsigned int) ((new_col.z + pixels[pos + 2] * sample) / (sample + 1));
                }
            }

            std::cout << "Rendered " << sample + 1 << " / " << samples << std::endl;
        }

        return pixels;
    };

    vec3 castRay(vec3 ro, vec3 rd, int depth = 0) {
        if (depth > recursion_limit) return 0;

        intersectionInfo intersection = getClosestIntersection(ro, rd);

        if (intersection.distance == max_distance) {
            return sky.color(rd);
        }

        vec3 reflection_o = ro + rd * intersection.distance;

        vec3 direction_to_light = light.pos - reflection_o;
        double direction_to_light_length = length(direction_to_light);

        direction_to_light = direction_to_light / direction_to_light_length;

        vec3 reflection_o_shifted = reflection_o - rd * 10e-5;

        if (direction_to_light_length > getClosestIntersection(reflection_o_shifted, direction_to_light).distance) {
            return 0;
        }

        vec3 illumination(0);

        vec3 normal_to_shape = intersection.shape->normal(reflection_o);

        // ambient
        illumination += intersection.shape->material->ambient;

        // diffuse
        if (intersection.shape->material->diffuse != vec3(0)) {
            illumination += intersection.shape->material->diffuse *
                            dot(direction_to_light, normal_to_shape);
        }

        // specular
        if (intersection.shape->material->shininess != 0) {
            vec3 H = norm(direction_to_light + norm(camera.pos - reflection_o));
            illumination += intersection.shape->material->specular *
                            pow(dot(normal_to_shape, H), intersection.shape->material->shininess);
        }

        // count reflection
        if (intersection.shape->material->reflection == 0) {
            return illumination;
        }

        vec3 color = castRay(
                reflection_o_shifted,
                intersection.shape->reflect(reflection_o, rd),
                depth + 1
        );

        if (color == 0) {
            return 0;
        }

        return illumination + color * intersection.shape->material->reflection;
    };

    intersectionInfo getClosestIntersection(vec3 ro, vec3 rd) {
        double min_distance = max_distance;
        int closest_shape_index = 0;
        double distance;

        for (int i = 0; i < shapes.size(); ++i) {
            distance = shapes[i]->intersection(ro, rd);

            if (distance < 0) continue;
            if (distance < min_distance) {
                min_distance = distance;
                closest_shape_index = i;
            }
        }

        return intersectionInfo(min_distance, shapes[closest_shape_index]);
    }
};

#endif //RAYTRACING_GRAPHICSMANAGER_H
