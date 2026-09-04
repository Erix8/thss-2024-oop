#include <cmath>

#include "Circle.h"

Circle::Circle(double radius) : Shape(radius) {}

double Circle::perimeter()
{
    return 2.0 * pi * size_;   // pi is inherited from Shape; size_ = radius
}

double Circle::area()
{
    return pi * size_ * size_;
}
