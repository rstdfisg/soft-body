#include "Node.hpp"

Node::Node()
{
    this->setXY(0.0f, 0.0f);
}

Node::Node(float x, float y)
{
    this->setXY(x, y);
}

Node::~Node()
{
    for (int i = 0; i < neighbor.size(); i++)
    {
        delete neighbor[i];
    }
}

void Node::setXY(float x, float y)
{
    this->nx = x;
    this->ny = y;
}

void Node::addNode(Node *node)
{
    this->neighbor.push_back(node);
}

float &Node::x()
{
    return this->nx;
}

float &Node::y()
{
    return this->ny;
}

int Node::getNodeSize()
{
    return this->neighbor.size();
}

std::vector<Node *>::iterator Node::begin()
{
    return this->neighbor.begin();
}

std::vector<Node *>::iterator Node::end()
{
    return this->neighbor.end();
}