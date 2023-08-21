#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System/Vector2.hpp>

#include "Node.hpp"

template <typename T>
T Vector2length(const sf::Vector2<T> &v)
{
    return std::sqrt(v.x * v.x + v.y * v.y);
}

int main()
{

    const uint32_t windowWidth = 1920;
    const uint32_t windowHeight = 1080;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Window");

    sf::CircleShape shape(600.5f);

    shape.setFillColor(sf::Color::Green);

    Node *aa = new Node(0.1f, 0.1f);
    Node *bb = new Node(20.1f, 20.1f);

    aa->addNode(bb);
    for (int i = 0; i < 5; i++)
    {
        aa->addNode(new Node(float(i) + 0.1f, float(i) + 0.1f));
    }

    std::cout << aa->x() << std::endl;
    std::cout << aa->getNodeSize() << std::endl;

    std::cout << bb << std::endl;

    for (auto i = aa->begin(); i != aa->end(); i++)
    {
        std::cout << (*i)->x() << std::endl;
        std::cout << *i << std::endl;
    }

    sf::Clock clock;
    window.setActive(true);
    window.setFramerateLimit(60);

    shape.setOrigin(0.0f, 0.0f);
    shape.setPosition(100.0f, 100.0f);

    double t = 0.0;
    double dt = 1.0 / 60.0;

    sf::VertexArray points(sf::Points, 1000 * 1000);

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            points[(1000 * i) + j].position = sf::Vector2f(i, j);
        }
    }

    while (window.isOpen())
    {
        // compute the FPS
        float currentTime = clock.restart().asSeconds();
        float fps = 1.0f / currentTime;
        // std::cout << "fps : " << fps << std::endl;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // // Clear screen
        window.clear();

        // update particle

        // Draw the sprite
        window.draw(points);

        // Update the window
        window.display();
    }

    return 0;
}