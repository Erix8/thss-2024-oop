#pragma once

#include "Point2D.h"

// A circular arc. Its bounding rectangle is boxTopLeft .. boxBottomRight,
// and the arc runs from arcBegin to arcEnd (used by CDC::Arc).
class Arc2D
{
public:
    Arc2D(double boxLeft, double boxTop, double boxRight, double boxBottom,
          double arcBeginX, double arcBeginY, double arcEndX, double arcEndY);
    Arc2D(const Point2D& boxTopLeft, const Point2D& boxBottomRight,
          const Point2D& arcBegin, const Point2D& arcEnd);
    Arc2D(const Arc2D& other);

    Point2D boxTopLeft;      // top-left of the bounding rectangle
    Point2D boxBottomRight;  // bottom-right of the bounding rectangle
    Point2D arcBegin;        // where the arc starts
    Point2D arcEnd;          // where the arc ends
};
