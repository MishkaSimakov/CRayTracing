#pragma once

#ifndef RAYTRACING_GRAPHICSMANAGER_H
#define RAYTRACING_GRAPHICSMANAGER_H

#include "iostream"
#include "variables.h"

class GraphicsManager {
public:
    const int width, height;
    sf::RenderWindow &window;

    GraphicsManager(sf::RenderWindow &_window, int _width, int _height)
            : window(_window),
              width(_width),
              height(_height) {};

    void draw() {
        auto pixels = new sf::Uint8[width * height * 4];

        vec3 ro(0);
        vec3 rd(0);
        Color col(0);

        vec2 size(width, height);

        int pos;

        for (int x = 0; x < width; ++x) {
            for (int y = 0; y < height; ++y) {
                ro = camera.pos;
                rd = norm(camera.getDirection(vec2(x, y), size));

                col = castRay(ro, rd) * 255;

                pos = (y * width + x) * 4;
                pixels[pos] = (col.r > 255) ? 255 : (unsigned char) (col.r);
                pixels[pos + 1] = (col.g > 255) ? 255 : (unsigned char) (col.g);
                pixels[pos + 2] = (col.b > 255) ? 255 : (unsigned char) (col.b);
                pixels[pos + 3] = 255;
            }
        }

        sf::Texture texture;
        texture.create(width, height);

        texture.update(pixels);

        sf::Sprite sprite;
        sprite.setTexture(texture);

        window.clear();
        window.draw(sprite);
    };

    Color castRay(vec3 ro, vec3 rd, int depth = 0) {
        if (depth > recursion_limit) return sky_color;

        double min_it = max_distance;
        char min_it_index = -1;

        for (char i = 0; i < shapes.size(); ++i) {
            double it = shapes[i]->intersection(ro, rd);

            if (it < 0) continue;
            if (it < min_it) {
                min_it = it;
                min_it_index = i;
            }
        }

        if (min_it_index != -1) {
            Shape *shape = shapes[min_it_index];

            vec3 reflection_o = ro + rd * (min_it - 1e-3);

            double diffuse_light_intensity = 0;

            for (char i = 0; i < lights.size(); ++i) {
                diffuse_light_intensity += lights[i]->intensity * std::max(
                        0.,
                        dot(norm(lights[i]->pos - reflection_o), shape->normal(reflection_o)
                    ));
            }

            return shape->material->color(reflection_o) * diffuse_light_intensity +
                   castRay(reflection_o, shape->reflect(reflection_o, rd), depth + 1) * shape->material->albedo;
        }

        return sky_color;
    };
};

#endif //RAYTRACING_GRAPHICSMANAGER_H
