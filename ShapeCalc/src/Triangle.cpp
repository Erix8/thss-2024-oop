#include <cmath>

#include "Triangle.h"

Triangle::Triangle(double side) : Shape(side) {}

double Triangle::perimeter()
{
    return 3.0 * size_;   // size_ was inherited from Shape
}

double Triangle::area()
{
    // Equilateral triangle area = (sqrt(3) / 4) * side^2.
    return (std::sqrt(3.0) / 4.0) * size_ * size_;
}
