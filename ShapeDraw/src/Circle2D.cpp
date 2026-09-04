#include "pch.h"
#include "Circle2D.h"

Circle2D::Circle2D(double centerX, double centerY, double radius)
    : center(centerX, centerY), radius(radius),
      startPoint(centerX - radius, centerY - radius),
      endPoint(centerX + radius, centerY + radius) {}

Circle2D::Circle2D(const Point2D& center, double radius)
    : center(center.x, center.y), radius(radius),
      startPoint(center.x - radius, center.y - radius),
      endPoint(center.x + radius, center.y + radius) {}

Circle2D::Circle2D(const Circle2D& other)
    : center(other.center), radius(other.radius),
      startPoint(other.startPoint), endPoint(other.endPoint) {}
