#pragma once

#include "Shape.h"

// A regular hexagon: a regular polygon with six equal sides.
class Hexagon : public Shape
{
public:
    Hexagon(double side);   // hand the side up to the base class

    double perimeter();
    double area();
};
