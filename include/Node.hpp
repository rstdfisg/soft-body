
#ifndef NODE_H
#define NODE_H

#include <vector>
#include "Edge.hpp"
#include <SFML/System/Vector2.hpp>

class Node
{
private:
    Edge *edges[2] = {nullptr};

    sf::Vector2f pos;
    sf::Vector2f prevPos;
    sf::Vector2f initPos;

    bool isPinned = false;
    bool isSelected = false;

    void keepInBox(int width, int height);

public:
    Node() = default;
    Node(float x, float y);
    ~Node() = default;

    void addEdge(Edge *edge, int index);

    void setPosition(float x, float y);
    const sf::Vector2f &getPosition();
    const bool getPinned();

    void pin();
    void update(
        float dt,
        float drag,
        const sf::Vector2f a,
        int boxWidth,
        int boxHeight,
        const sf::RenderWindow *window);
};

#endif
