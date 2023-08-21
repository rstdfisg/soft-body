
#ifndef NODE_H
#define NODE_H

#include <vector>
#include <list>

class Node
{
public:
    Node();
    Node(float, float);
    void setXY(float, float);
    void addNode(Node *node);
    int getNodeSize();
    ~Node();
    float &x();
    float &y();
    std::vector<Node *>::iterator begin();
    std::vector<Node *>::iterator end();

private:
    float nx;
    float ny;

    std::vector<Node *> neighbor;
};

class NodeController
{
public:
    NodeController();

private:
    std::list<Node *> allNode;
};

#endif
