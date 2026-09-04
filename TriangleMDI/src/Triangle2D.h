#pragma once
#include"Point2D.h"
class Triangle2D
{
public:
	Point2D vertex1, vertex2, vertex3;
public:
	Triangle2D(double x1 = 0.0, double y1 = 0.0, double x2 = 0.0,
		double y2 = 0.0, double x3 = 0.0, double y3 = 0.0);
	Triangle2D(const Point2D& a, const Point2D& b, const Point2D& c);
	Triangle2D(const Triangle2D& s);
	virtual ~Triangle2D() {};
};