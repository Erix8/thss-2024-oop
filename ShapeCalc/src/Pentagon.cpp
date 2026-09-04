#include <cmath>

#include "Pentagon.h"

Pentagon::Pentagon(double side) : Shape(side) {}

double Pentagon::perimeter()
{
    return 5.0 * size_;   // size_ was inherited from Shape
}

double Pentagon::area()
{
    // Regular n-gon area = (n/4) * side^2 * cot(pi/n). For n = 5 that is
    // (5/4) * size_^2 / tan(pi/5).  pi is inherited from Shape.
    return (5.0 / 4.0) * size_ * size_ / std::tan(pi / 5.0);
}
