#include "Square.h"

Square::Square(double side) : Shape(side) {}

double Square::perimeter()
{
    return 4.0 * size_;   // size_ was inherited from Shape
}

double Square::area()
{
    return size_ * size_;
}
