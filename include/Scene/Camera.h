#pragma once

#ifndef RAYTRACING_CAMERA_H
#define RAYTRACING_CAMERA_H

#include <cmath>

#include "../VecFunctions.h"
#include "SFML/Graphics.hpp"
#include "../Mat2.h"

class Camera {
public:
    const double MOVEMENT_SPEED = 1;

    vec3 pos;
    vec3 direction = vec3(0, 0, -1);

    bool is_mouse_fixed = false;
    double fov = tan(3.14 / 3 / 2.);

    vec3 speed = vec3(0);
    double braking;

    Camera(vec3 _pos, vec3 _direction, double _braking = 1) : pos(_pos), braking(_braking) {};

    void update(double deltaTime, sf::RenderWindow &window) {
        if (is_mouse_fixed) {
            vec2 half_size = vec2(window.getSize().x, window.getSize().y) / 2.;

            rotateCamera(vec2(
                    (int) half_size.x - sf::Mouse::getPosition(window).x,
                    (int) half_size.y - sf::Mouse::getPosition(window).y
            ));
            sf::Mouse::setPosition(sf::Vector2i(half_size.x, half_size.y), window);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            speed.y = MOVEMENT_SPEED;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            speed.y = -MOVEMENT_SPEED;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            speed.x = -MOVEMENT_SPEED;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            speed.x = MOVEMENT_SPEED;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
            is_mouse_fixed = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
            is_mouse_fixed = false;


        if (speed.x != 0) {
            if (speed.x < 0) speed.x = std::min(0.0, speed.x + braking * deltaTime);
            else speed.x = std::max(0.0, speed.x - braking * deltaTime);
        }

        if (speed.y != 0) {
            if (speed.y < 0) speed.y = std::min(0.0, speed.y + braking * deltaTime);
            else speed.y = std::max(0.0, speed.y - braking * deltaTime);
        }

        pos = pos + speed * deltaTime;
    }

    vec3 getDirection(vec2 point, vec2 size) {
        vec2 uv = point / vec2(std::max(size.x, size.y));
        vec3 rayDirection = norm(vec3(1.0, uv));

        vec2 zx = rot(-direction.y) * vec2(rayDirection.z, rayDirection.x);
        rayDirection.z = zx.x;
        rayDirection.x = zx.y;

        vec2 xy = rot(direction.x) * vec2(rayDirection.x, rayDirection.y);
        rayDirection.x = xy.x;
        rayDirection.y = xy.y;

//        double x = size.x / 2. - point.x;
//        double y = -size.y / 2. + point.y;

        return rayDirection;
    }

    void rotateCamera(vec2 offset) {
        direction.x += offset.x / 600;
        direction.y += offset.y / 600;
    }

    static mat2 rot(float a) {
        float s = std::sin(a);
        float c = std::cos(a);
        return mat2(c, -s, s, c);
    }
};

#endif //RAYTRACING_CAMERA_H
