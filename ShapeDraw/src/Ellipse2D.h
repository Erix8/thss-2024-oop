#pragma once

#include "Point2D.h"

// An axis-aligned ellipse described by its centre and the two semi-axis
// lengths (a along x, b along y). The bounding-box corners are computed so
// the ellipse can be drawn with CDC::Ellipse.
class Ellipse2D
{
public:
    Ellipse2D(double centerX = 0.0, double centerY = 0.0,
              double semiX = 0.0, double semiY = 0.0);
    Ellipse2D(const Point2D& center, double semiX, double semiY);
    Ellipse2D(const Ellipse2D& other);

    Point2D center;        // centre of the ellipse
    double  semiX;         // half width along x (a)
    double  semiY;         // half height along y (b)
    Point2D startPoint;    // top-left corner of the bounding box
    Point2D endPoint;      // bottom-right corner of the bounding box
};
