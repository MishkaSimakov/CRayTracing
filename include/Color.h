#pragma once

#ifndef RAYTRACING_COLOR_H
#define RAYTRACING_COLOR_H

#include "Vec3.h"
#include "SFML/Graphics.hpp"

class Color {
public:
    double r, g, b;

    Color(double _value) : r(_value), g(_value), b(_value) {};
    Color(vec3 v) : r(v.x), g(v.y), b(v.z) {};
    Color(double _r, double _g, double _b) : r(_r), g(_g), b(_b) {};

    Color operator+(Color other) { return Color(r + other.r, g + other.g, b + other.b); }
    Color operator*(Color other) { return Color(r * other.r, g * other.g, b * other.b); }
    Color operator/(Color other) { return Color(r / other.r, g / other.g, b / other.b); }

    Color corrected() {
//        Color col = Color(r, g, b, a);
//
//        float white = 20.0;
//        col = col * white * 16.0;
//        col = (col * (col / white / white + 1.0)) / (col + 1.0);
//
//        return col;

//        double gamma = 1;
//        return Color(pow(r, gamma), pow(g, gamma), pow(b, gamma));

        return *this;
    }

    sf::Color getSFMLColor() {
        return sf::Color(
                std::min(r * 255, 255.0),
                std::min(g * 255, 255.0),
                std::min(b * 255, 255.0),
                255
        );
    }
};

#endif //RAYTRACING_COLOR_H
