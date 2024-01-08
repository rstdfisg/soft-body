
#ifndef EDGE_H
#define EDGE_H

#include <cstdint>
#include <SFML/Graphics.hpp>

class Node;
class Edge
{
private:
    Node &node1;
    Node &node2;

    float length;

    bool isActive = true;
    bool isSelected = false;

    uint32_t color = 0xFFFFFFFF;
    uint32_t colorWhenSelected = 0xFF4D4DEE;

public:
    Edge(Node &node1, Node &node2, float length);
    ~Edge() = default;

    void setIsSelected(bool value);
    void inActive();
    void update();
    void draw(sf::RenderWindow &window);
};

#endif