#ifndef CLOTH_H
#define CLOTH_H

#include "Edge.hpp"
#include "Node.hpp"
#include <vector>
#include <list>
#include <SFML/System/Vector2.hpp>

class Cloth
{
private:
    sf::Vector2f gravity = {0.0f, 981.0f};
    float drag = 0.01f;
    float elasticity = 10.0f;

    std::vector<Node *> nodes;
    std::vector<Edge *> edges;

public:
    Cloth(int width, int height, int interval, int x0, int y0);
    ~Cloth();
    void update(const sf::RenderWindow *window, float dt);
    void draw(sf::RenderWindow &window) const;
};

#endif