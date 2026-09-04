#include "pch.h"
#include "Ellipse2D.h"

Ellipse2D::Ellipse2D(double centerX, double centerY, double semiX, double semiY)
    : center(centerX, centerY), semiX(semiX), semiY(semiY),
      startPoint(centerX - semiX, centerY - semiY),
      endPoint(centerX + semiX, centerY + semiY) {}

Ellipse2D::Ellipse2D(const Point2D& center, double semiX, double semiY)
    : center(center.x, center.y), semiX(semiX), semiY(semiY),
      startPoint(center.x - semiX, center.y - semiY),
      endPoint(center.x + semiX, center.y + semiY) {}

Ellipse2D::Ellipse2D(const Ellipse2D& other)
    : center(other.center), semiX(other.semiX), semiY(other.semiY),
      startPoint(other.startPoint), endPoint(other.endPoint) {}
