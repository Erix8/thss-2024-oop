#include "pch.h"
#include"Triangle2D.h"

Triangle2D::Triangle2D(double x1, double y1, double x2,
	double y2, double x3, double y3) :vertex1(x1, y1), vertex2(x2, y2), vertex3(x3, y3) {};
Triangle2D::Triangle2D(const Point2D& a, const Point2D& b,
	const Point2D& c) :vertex1(a), vertex2(b), vertex3(c) {};
Triangle2D::Triangle2D(const Triangle2D& s) :vertex1(s.vertex1), vertex2(s.vertex2), vertex3(s.vertex3) {};

