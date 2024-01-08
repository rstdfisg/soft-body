#include "Node.hpp"
#include "Edge.hpp"
#include "Cloth.hpp"
#include <SFML/System/Vector2.hpp>

Cloth::Cloth(int width, int height, int interval, int x0, int y0)
{
    for (int y = 0; y <= height; y++)
    {
        for (int x = 0; x <= width; x++)
        {
            Node *node = new Node(x0 + x * interval, y0 + y * interval);

            if (x != 0)
            {
                Node *leftnode = nodes[this->nodes.size() - 1];
                Edge *edge = new Edge(*node, *leftnode, interval);
                leftnode->addEdge(edge, 0);
                node->addEdge(edge, 0);
                edges.push_back(edge);
            }

            if (y != 0)
            {
                Node *upnode = nodes[x + (y - 1) * (width + 1)];
                Edge *edge = new Edge(*node, *upnode, interval);
                upnode->addEdge(edge, 1);
                node->addEdge(edge, 1);
                edges.push_back(edge);
            }

            // pin condition
            if (y == 0 && x % 10 == 0)
            {
                node->pin();
            }

            nodes.push_back(node);
        }
    }
}

Cloth::~Cloth()
{
    for (Node *node : nodes)
    {
        delete node;
    }

    for (Edge *edge : edges)
    {
        delete edge;
    }
}

void Cloth::update(const sf::RenderWindow *window, float dt)
{
    sf::Vector2u size = window->getSize();
    for (std::size_t i = 0; i < nodes.size(); i++)
    {
        Node *node = nodes[i];
        node->update(dt, drag, gravity, size.x, size.y, window);
    }

    for (std::size_t i = 0; i < edges.size(); i++)
    {
        edges[i]->update();
    }
}

void Cloth::draw(sf::RenderWindow &window) const
{
    for (std::size_t i = 0; i < edges.size(); i++)
    {
        edges[i]->draw(window);
    }
}
