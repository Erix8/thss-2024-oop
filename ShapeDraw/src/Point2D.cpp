#include "pch.h"
#include "Point2D.h"

Point2D::Point2D(double x, double y) : x(x), y(y) {}

Point2D::Point2D(const Point2D& other) : x(other.x), y(other.y) {}
