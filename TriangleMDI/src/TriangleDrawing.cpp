#include"pch.h"
#include"TriangleDrawing.h"

extern void DrawTriangle(CDC& d, const Triangle2D& s, int style, int r, int g, int b)
{
	CPen Pen(style, 3, RGB(r, g, b));
	CPen* oldPen = d.SelectObject(&Pen);
	d.MoveTo((int)(s.vertex1.x + 0.5), (int)(s.vertex1.y + 0.5));
	d.LineTo((int)(s.vertex2.x + 0.5), (int)(s.vertex2.y + 0.5));
	d.LineTo((int)(s.vertex3.x + 0.5), (int)(s.vertex3.y + 0.5));
	d.LineTo((int)(s.vertex1.x + 0.5), (int)(s.vertex1.y + 0.5));
	d.SelectObject(oldPen);
}