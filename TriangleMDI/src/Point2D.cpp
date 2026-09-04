#include"pch.h"
#include"Point2D.h"

Point2D::Point2D(double newx, double newy)
	:x(newx), y(newy) {}
Point2D::Point2D(const Point2D& p) :x(p.x), y(p.y) {}