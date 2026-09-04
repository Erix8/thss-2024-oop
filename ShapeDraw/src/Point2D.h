#pragma once

// A simple 2-D point (x, y), used to position the shapes that make up the
// picture drawn in the view.
class Point2D
{
public:
    Point2D(double x = 0.0, double y = 0.0);   // default is the origin (0,0)
    Point2D(const Point2D& other);             // copy constructor

    double x;
    double y;
};
