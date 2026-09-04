#pragma once

#include "Shape.h"

// A square: a regular quadrilateral with four equal sides.
class Square : public Shape
{
public:
    Square(double side);   // hand the side up to the base class

    double perimeter();
    double area();
};
