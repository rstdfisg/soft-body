#include "Rectangle.hpp"

Rectangle::Rectangle()
{
    setXY(1, 1);
}

Rectangle::Rectangle(double x, double y)
{
    setXY(x, y);
}

void Rectangle::setXY(double x, double y)
{
    m_x = x;
    m_y = y;
}

double Rectangle::getArea(void)
{
    return m_x * m_y;
}