#include <cmath>

#include "Hexagon.h"

Hexagon::Hexagon(double side) : Shape(side) {}

double Hexagon::perimeter()
{
    return 6.0 * size_;   // size_ was inherited from Shape
}

double Hexagon::area()
{
    // Regular n-gon area = (n/4) * side^2 * cot(pi/n). For n = 6 that is
    // (6/4) * size_^2 / tan(pi/6).  pi is inherited from Shape.
    return (6.0 / 4.0) * size_ * size_ / std::tan(pi / 6.0);
}
