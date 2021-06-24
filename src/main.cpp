#include "../include/GraphicsManager.h"


double get_height_from_position(int x, int y) {
    return height_map[x * map_height + y];
}

int main() {
//    colors
    vec3 grass_color = vec3(77, 250, 57) / 255;

//    materials
    Material grass_material(
            vec3(0, 0.1, 0),
            grass_color,
            vec3(1, 1, 1),
            0, 0
    );

    Material mirror_material(
            vec3(0, 0, 0),
            vec3(0, 0, 0),
            vec3(1, 1, 1),
            0.9, 0
    );

    Material red_material(
            vec3(0.1, 0, 0),
            vec3(0.7, 0, 0),
            vec3(1, 1, 1),
            0.5, 50
    );

//    shapes
    vec3 map_start_point = vec3(-9, 2, 2);

    for (double &x : height_map) {
        x = rand() % 10 / 20.;
    }

    for (int x = 1; x < map_width; ++x) {
        for (int y = 1; y < map_height; ++y) {
            shapes.push_back(new Triangle(
                    vec3(map_start_point.x + x - 1, map_start_point.y + get_height_from_position(x - 1, y),
                         map_start_point.z + y),
                    vec3(map_start_point.x + x - 1, map_start_point.y + get_height_from_position(x - 1, y - 1),
                         map_start_point.z + y - 1),
                    vec3(map_start_point.x + x, map_start_point.y + get_height_from_position(x, y),
                         map_start_point.z + y),
                    &grass_material
            ));

            shapes.push_back(new Triangle(
                    vec3(map_start_point.x + x, map_start_point.y + get_height_from_position(x, y - 1),
                         map_start_point.z + y - 1),
                    vec3(map_start_point.x + x, map_start_point.y + get_height_from_position(x, y),
                         map_start_point.z + y),
                    vec3(map_start_point.x + x - 1, map_start_point.y + get_height_from_position(x - 1, y - 1),
                         map_start_point.z + y - 1),
                    &grass_material
            ));
        }
    }


    shapes.push_back(new Triangle(
            vec3(-1, -1, 7),
            vec3(1, -1, 7),
            vec3(-1, 1, 8),
            &mirror_material
    ));
    shapes.push_back(new Triangle(
            vec3(1, 1, 8),
            vec3(1, -1, 7),
            vec3(-1, 1, 8),
            &mirror_material
    ));

//    shapes.push_back(new Sphere(vec3(-1, 0, 5), 0.5, &red_material));


//    init graphics manager
    GraphicsManager graphicsManager(WIDTH, HEIGHT);

//    render image
    sf::Image rendered;
    rendered.create(WIDTH, HEIGHT);

    int pos;
    auto pixels = graphicsManager.draw(samples_count);

    for (int x = 0; x < WIDTH; ++x) {
        for (int y = 0; y < HEIGHT; ++y) {
            pos = (y * WIDTH + x) * 3;

            rendered.setPixel(x, y, sf::Color(
                    pixels[pos],
                    pixels[pos + 1],
                    pixels[pos + 2],
                    255
            ));
        }
    }
    rendered.saveToFile(image_path);

    return 0;
}