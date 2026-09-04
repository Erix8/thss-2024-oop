#pragma once

class Point2D
{
public:
	double x, y;
public:
	Point2D(double newx = 0.0, double newy = 0.0);
	Point2D(const Point2D& p);
};