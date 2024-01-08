#include <string>
#include <iostream>
#include <algorithm>
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
    window.setFramerateLimit(200);

    Cloth *pCloth = new Cloth(120, 50, 10, 200, 0);

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
                    delete pCloth;
                    window.close();
                }
                break;

            case sf::Event::Resized:
                break;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            delete pCloth;
            pCloth = new Cloth(120, 50, 10, 200, 0);
        }

        // Clear screen
        window.clear();

        // update object and draw
        pCloth->update(&window, dt.asSeconds());
        pCloth->draw(window);

        // Update the window
        window.display();
    }

    return 0;
}