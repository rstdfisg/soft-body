#include "Node.hpp"
#include "Edge.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include "helper.cpp"

Edge::Edge(Node &node1, Node &node2, float length)
    : node1(node1), node2(node2), length(length)
{
}

void Edge::setIsSelected(bool value)
{
    isSelected = value;
}

void Edge::inActive()
{
    isActive = false;
}

// small modification after node updating
void Edge::update()
{
    if (!isActive)
    {
        return;
    }

    bool node1Fix = node1.getPinned();
    bool node2Fix = node2.getPinned();

    if (node1Fix && node2Fix)
    {
        return;
    }

    sf::Vector2f pos1 = node1.getPosition();
    sf::Vector2f pos2 = node2.getPosition();

    sf::Vector2f diffvec = pos1 - pos2;

    float distance = Vector2length<float>(diffvec);
    float diffFactor = (length - distance) / distance;

    if (node1Fix)
    {
        sf::Vector2f offset = diffvec * diffFactor;
        node2.setPosition(pos2.x - offset.x, pos2.y - offset.y);
        return;
    }

    if (node2Fix)
    {
        sf::Vector2f offset = diffvec * diffFactor;
        node1.setPosition(pos1.x + offset.x, pos1.y + offset.y);
        return;
    }

    sf::Vector2f offset = diffvec * diffFactor * 0.5f;
    node1.setPosition(pos1.x + offset.x, pos1.y + offset.y);
    node2.setPosition(pos2.x - offset.x, pos2.y - offset.y);

    return;
}

void Edge::draw(sf::RenderWindow &window)
{
    if (!isActive)
    {
        return;
    }

    sf::Vector2f pos1 = node1.getPosition();
    sf::Vector2f pos2 = node2.getPosition();

    sf::Color cc = sf::Color(isSelected ? colorWhenSelected : color);

    sf::Vertex lines[] =
        {
            sf::Vertex(pos1, cc),
            sf::Vertex(pos2, cc)};

    window.draw(lines, 2, sf::Lines);
}
