#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{

private:
    double m_x;
    double m_y;

public:
    Rectangle();
    Rectangle(double, double);
    void setXY(double, double);
    double getArea();
};

#endif