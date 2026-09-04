#include "pch.h"
#include "Arc2D.h"

Arc2D::Arc2D(double boxLeft, double boxTop, double boxRight, double boxBottom,
             double arcBeginX, double arcBeginY, double arcEndX, double arcEndY)
    : boxTopLeft(boxLeft, boxTop),
      boxBottomRight(boxRight, boxBottom),
      arcBegin(arcBeginX, arcBeginY),
      arcEnd(arcEndX, arcEndY) {}

Arc2D::Arc2D(const Point2D& boxTopLeft, const Point2D& boxBottomRight,
             const Point2D& arcBegin, const Point2D& arcEnd)
    : boxTopLeft(boxTopLeft.x, boxTopLeft.y),
      boxBottomRight(boxBottomRight.x, boxBottomRight.y),
      arcBegin(arcBegin.x, arcBegin.y),
      arcEnd(arcEnd.x, arcEnd.y) {}

Arc2D::Arc2D(const Arc2D& other)
    : boxTopLeft(other.boxTopLeft),
      boxBottomRight(other.boxBottomRight),
      arcBegin(other.arcBegin),
      arcEnd(other.arcEnd) {}
