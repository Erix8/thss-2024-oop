#pragma once

#include "Point2D.h"

// A circle described by its centre and radius. The bounding-box corners
// (start/end) make it easy to call CDC::Ellipse later.
class Circle2D
{
public:
    Circle2D(double centerX = 0.0, double centerY = 0.0, double radius = 0.0);
    Circle2D(const Point2D& center, double radius);
    Circle2D(const Circle2D& other);

    Point2D center;        // centre of the circle
    double  radius;        // radius of the circle
    Point2D startPoint;    // top-left corner of the bounding square
    Point2D endPoint;      // bottom-right corner of the bounding square
};
