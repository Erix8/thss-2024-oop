#pragma once

#include "Shape.h"

// A regular pentagon: a regular polygon with five equal sides.
class Pentagon : public Shape
{
public:
    Pentagon(double side);   // hand the side up to the base class

    double perimeter();
    double area();
};
