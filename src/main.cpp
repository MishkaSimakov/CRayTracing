#include "../include/GraphicsManager.h"


int main() {
    vec3 metal_color = vec3(123, 144, 149) / 255;
    vec3 brick_color = vec3(220, 85, 57) / 255;

    Material mat1(brick_color, 0.1, 0.95);
    Sphere sphere(vec3(0, 3, -5), 1, &mat1);
    shapes.push_back(&sphere);

    Material mat2(metal_color, 0.8, 0);
    Sphere sphere2(vec3(0, -2, -5), 2, &mat2);
    shapes.push_back(&sphere2);

    Light light(vec3 (-5, -5, -10), 1, 1);
    lights.push_back(&light);

    ChessMaterial mat3;
    Plane plane(vec3(0, 0, 0), norm(vec3(0, 0, -1)), &mat3);
    shapes.push_back(&plane);

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "3D ray casting");
    window.setMouseCursorVisible(false);

    GraphicsManager graphicsManager(window, WIDTH, HEIGHT);

    if (!save_to_image) {
        double deltaTime;
        double time = 0;
        sf::Clock clock;

        while (window.isOpen()) {
            deltaTime = clock.restart().asSeconds();

            sf::Event event{};
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            camera.update(deltaTime, window);

            graphicsManager.draw();
            window.display();

            time += deltaTime;

            std::cout << "-----------------" << std::endl;
            std::cout << "Position: " << camera.pos.x << " " << camera.pos.y << " " << camera.pos.z << std::endl;
            std::cout << "Direction: " << camera.direction.x << " " << camera.direction.y << " " << camera.direction.z << std::endl;
        }
    } else {
        sf::Image rendered;
        rendered.create(WIDTH, HEIGHT);

        auto pixels = new sf::Uint8[WIDTH * HEIGHT * 3];

        vec2 size(WIDTH, HEIGHT);

        vec3 ro(0);
        vec3 rd(0);
        Color col(0);

        int pos;

        std::cout << "Start rendering..." << std::endl;

        for (int sample = 0; sample < samples; ++sample) {
            for (int x = 0; x < WIDTH; ++x) {
                for (int y = 0; y < HEIGHT; ++y) {
                    ro = camera.pos;
                    rd = norm(camera.getDirection(vec2(x, y), size));

                    col = graphicsManager.castRay(ro, rd) * 255;

                    vec3 new_col = vec3(
                            (col.r > 255) ? 255 : col.r,
                            (col.g > 255) ? 255 : col.g,
                            (col.b > 255) ? 255 : col.b
                    );

                    pos = (y * WIDTH + x) * 3;
                    pixels[pos] = (unsigned int) ((new_col.x + pixels[pos] * sample) / (sample + 1));
                    pixels[pos + 1] = (unsigned int) ((new_col.y + pixels[pos + 1] * sample) / (sample + 1));
                    pixels[pos + 2] = (unsigned int) ((new_col.z + pixels[pos + 2] * sample) / (sample + 1));
                }
            }

            std::cout << "Rendered " << sample + 1 << " / " << samples << std::endl;
        }


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
    }

    return 0;
}