#pragma once

// Base class for every shape in this homework. Each shape is described by a
// single length: the side of a regular polygon, or the radius of a circle.
// Derived classes inherit that length and add their own way to compute
// perimeter and area. (This is "inheritance only": no virtual functions yet.)
class Shape
{
public:
    Shape(double size);      // constructor: remember the size

protected:
    double pi = 3.141592653589793;   // pi, shared with every derived shape
    double size_;                    // a side length (or radius), available to derived classes
};
