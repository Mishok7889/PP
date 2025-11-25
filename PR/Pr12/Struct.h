#pragma once
#include <memory>

struct Point {
    int _x, _y;
    ~Point()
	{
		std::cout << "Point::Destructor called" << std::endl;
	}
	void move(int dx, int dy) { _x += dx; _y += dy; }
};
std::ostream& operator<<(std::ostream& os, const Point& u)
{
	return os << u._x << ',' << u._y;
}

std::unique_ptr<Point> clone(Point& x) {
	return std::make_unique<Point>(x);
}
