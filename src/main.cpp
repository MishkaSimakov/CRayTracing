#include "../include/GraphicsManager.h"


int main() {
    vec3 const metal_color = vec3(123, 144, 149) / 255;
    vec3 const brick_color = vec3(220, 85, 57) / 255;
    vec3 const skin_color = vec3(229, 194, 152) / 255;

    Material mat1(brick_color, 0.1);
    Sphere sphere(vec3(0, 5, -5), 1, &mat1);
    shapes.push_back(&sphere);

    Material mat2(metal_color, 0.8);
    Sphere sphere2(vec3(0, 0, -5), 2, &mat2);
    shapes.push_back(&sphere2);

    Light light(vec3 (-5, -5, -10), 1, 1);
    lights.push_back(&light);

    ChessMaterial mat3;
    Plane plane(vec3(0, 0, 0), norm(vec3(0, 0, -1)), &mat3);
    shapes.push_back(&plane);



    Material player_material(skin_color, 0);
    Sphere player(vec3(0), 1, &player_material);
    shapes.push_back(&player);

    sf::RenderWindow window(sf::VideoMode(w, h), "3D ray casting");
    window.setMouseCursorVisible(false);

    GraphicsManager graphicsManager(window, w, h);

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

            player.pos = camera.pos;
            time += deltaTime;
        }
    } else {
//        sf::Image rendered;
//        rendered.create(w, h);
//
//        for (int x = 0; x < w; ++x) {
//            for (int y = 0; y < h; ++y) {
//                rendered.setPixel(x, y, graphicsManager.getColor(vec2(x, y)).getSFMLColor());
//            }
//        }
//
//        rendered.saveToFile(path);
    }

    return 0;
}