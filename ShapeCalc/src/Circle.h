#pragma once

#include "Shape.h"

// A circle, described by its radius.
class Circle : public Shape
{
public:
    Circle(double radius);   // hand the radius up to the base class

    double perimeter();   // circumference
    double area();
};
