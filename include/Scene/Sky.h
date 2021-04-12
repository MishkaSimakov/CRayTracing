//
// Created by msima on 12.04.2021.
//

#ifndef RAYTRACING_SKY_H
#define RAYTRACING_SKY_H

#include "../Math/Mat3.h"

class Sky {
public:
    sf::Image image;

    const double c = std::cos(M_PI_4);
    const double s = std::sin(M_PI_4);
    Mat3 rotation = Mat3(
            vec3(1, 0, 0),
            vec3(0, c, -s),
            vec3(0, s, c)
    );

    Sky(std::string path) {
        image.loadFromFile(path);
    };

    Color color(vec3 rd) {
        return Color(0.01, 0.86, 1.0);

//        rd = rotation * rd;
//
//        if (rd.z == 1) return Color(1);
//
//        std::cout << rd.y << " " << rd.z << std::endl;
//
//        int x = (rd.x / (1 - rd.z) + 1) * 200;
//        int y = (rd.y / (1 - rd.z) + 1) * 400;
//
//        sf::Color col = image.getPixel(y, x);
//
//        return Color(col.r / 255., col.g / 255., col.b / 255.);
    }
};

#endif //RAYTRACING_SKY_H
