#include "Node.hpp"
#include "Edge.hpp"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>

Node::Node(float x, float y)
{
    pos = prevPos = initPos = sf::Vector2f(x, y);
}

void Node::setPosition(float x, float y)
{
    pos.x = x;
    pos.y = y;
}

const sf::Vector2f &Node::getPosition()
{
    return pos;
}

void Node::addEdge(Edge *edge, int index)
{
    edges[index] = edge;
}

const bool Node::getPinned()
{
    return isPinned;
}

void Node::pin()
{
    isPinned = true;
}

// integration method to update two node
void Node::update(float dt, float drag, const sf::Vector2f a, int boxWidth, int boxHeight, const sf::RenderWindow *window)
{

    // mouse selection
    bool isSelected = false;

    sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(*window));
    sf::Vector2f cursorDiff = pos - mousePos;
    float cursorDist = cursorDiff.x * cursorDiff.x + cursorDiff.y * cursorDiff.y;

    isSelected = cursorDist < 2000.0f;

    for (Edge *edge : edges)
    {
        if (edge != nullptr)
        {
            edge->setIsSelected(isSelected);
        }
    }

    bool leftPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    bool rightPressed = sf::Mouse::isButtonPressed(sf::Mouse::Right);

    if (leftPressed && isSelected)
    {
        prevPos -= cursorDiff * 0.1f;
    }

    if (rightPressed && isSelected)
    {
        for (Edge *edge : edges)
        {
            if (edge != nullptr)
                edge->disconnet();
        }
    }

    // update node
    if (isPinned)
    {
        pos = initPos;
        return;
    }

    float decayCoff = (1.0f - drag);
    sf::Vector2f newPos = pos + (pos - prevPos) * decayCoff + a * decayCoff * dt * dt;

    prevPos = pos;
    pos = newPos;

    keepInBox(boxWidth, boxHeight);
}

void Node::keepInBox(int width, int height)
{
    if (pos.x > width)
    {
        pos.x = width;
        prevPos.x = pos.x;
    }
    else if (pos.x < 0)
    {
        pos.x = 0;
        prevPos.x = pos.x;
    }

    if (pos.y > 3 * height)
    {
        for (Edge *edge : edges)
        {
            if (edge != nullptr)
                edge->disconnet();
        }
        // pos.y = height;
        // prevPos.y = pos.y;
    }

    else if (pos.y < 0)
    {
        pos.y = 0;
        prevPos.y = pos.y;
    }
}