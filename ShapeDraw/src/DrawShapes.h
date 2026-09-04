#pragma once

#include "pch.h"          // brings in the MFC/ATL headers (CDC, CPen, CBrush, ...)
#include "Arc2D.h"
#include "Circle2D.h"
#include "Ellipse2D.h"

// Draw a circle filled with the given colour.
void DrawCircle(CDC& dc, const Circle2D& circle, int style,
                int red, int green, int blue);

// Draw an elliptical arc with the given pen colour.
void DrawArc(CDC& dc, const Arc2D& arc, int style,
             int red, int green, int blue);

// Draw an ellipse filled with the given colour.
void DrawEllipse(CDC& dc, const Ellipse2D& ellipse, int style,
                 int red, int green, int blue);
