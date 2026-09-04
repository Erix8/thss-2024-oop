#pragma once

#include "Shape.h"

// An equilateral (regular) triangle: inherits the side length from Shape.
class Triangle : public Shape
{
public:
    Triangle(double side);   // hand the side up to the base class

    double perimeter();
    double area();
};
