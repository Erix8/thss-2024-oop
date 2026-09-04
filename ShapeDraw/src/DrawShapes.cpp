#include "pch.h"
#include "DrawShapes.h"

// Round helper used below to convert a double coordinate into an int.
static int ToInt(double value)
{
    return (int)(value + 0.5);
}

void DrawCircle(CDC& dc, const Circle2D& circle, int style,
                int red, int green, int blue)
{
    CPen pen(style, 5, RGB(0, 0, 0));
    CPen* oldPen = dc.SelectObject(&pen);
    CBrush brush(RGB(red, green, blue));
    CBrush* oldBrush = dc.SelectObject(&brush);

    dc.Ellipse(ToInt(circle.startPoint.x), ToInt(circle.startPoint.y),
               ToInt(circle.endPoint.x), ToInt(circle.endPoint.y));

    dc.SelectObject(oldPen);
    dc.SelectObject(oldBrush);
}

void DrawArc(CDC& dc, const Arc2D& arc, int style,
             int red, int green, int blue)
{
    CPen pen(style, 5, RGB(red, green, blue));
    CPen* oldPen = dc.SelectObject(&pen);

    dc.Arc(ToInt(arc.boxTopLeft.x), ToInt(arc.boxTopLeft.y),
           ToInt(arc.boxBottomRight.x), ToInt(arc.boxBottomRight.y),
           ToInt(arc.arcBegin.x), ToInt(arc.arcBegin.y),
           ToInt(arc.arcEnd.x), ToInt(arc.arcEnd.y));

    dc.SelectObject(oldPen);
}

void DrawEllipse(CDC& dc, const Ellipse2D& ellipse, int style,
                 int red, int green, int blue)
{
    CPen pen(style, 1, RGB(0, 0, 0));
    CPen* oldPen = dc.SelectObject(&pen);
    CBrush brush(RGB(red, green, blue));
    CBrush* oldBrush = dc.SelectObject(&brush);

    dc.Ellipse(ToInt(ellipse.startPoint.x), ToInt(ellipse.startPoint.y),
               ToInt(ellipse.endPoint.x), ToInt(ellipse.endPoint.y));

    dc.SelectObject(oldPen);
    dc.SelectObject(oldBrush);
}
