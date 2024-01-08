#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Node.hpp"
#include "Cloth.hpp"

int main()
{
    const uint32_t windowWidth = 1920;
    const uint32_t windowHeight = 1080;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 2;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Window", sf::Style::Default, settings);

    sf::Clock clock;

    window.setActive(true);
    window.setFramerateLimit(120);

    Cloth cloth = Cloth(120, 50, 10, 200, 0);
    while (window.isOpen())
    {
        // compute the FPS
        // float currentTime = clock.restart().asSeconds();
        // float fps = 1.0f / currentTime;
        // printf("fps: %10f \n", fps);

        sf::Time dt = sf::seconds(0.01f);
        // sf::Time dt = deltaClock.restart();
        // printf("dt: %10f \n", dt.asSeconds());
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {

            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::MouseMoved:

                // printf("x=%d ", event.mouseMove.x);
                // printf("y=%d \n", event.mouseMove.y);
                break;

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
                break;

            case sf::Event::Resized:
                printf("___ \n\n\n\n");
            }
        }

        // Clear screen
        window.clear();

        // if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        // {
        //     sf::Vector2i mousePos = sf::Mouse::getPosition();
        //     printf("%d, %d \n", mousePos.x, mousePos.y);
        // }

        // update object and draw
        cloth.update(&window, dt.asSeconds());
        cloth.draw(window);

        // Update the window
        window.display();
    }

    return 0;
}