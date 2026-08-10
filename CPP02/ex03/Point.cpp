#include "Point.hpp"

Point::Point(void) : x(0), y(0) {}

Point::Point(const Fixed x, const Fixed y) : x(x), y(y) {}

const Fixed&	Point::getFixedX() const
{
	return	this->x;
}

const Fixed&	Point::getFixedY() const
{
	return	this->y;
}

Point::Point(const Point& other) : x(other.getFixedX()), y(other.getFixedY()) {}

Point::~Point(void) {}

void Point::operator=(const Point& other)
{
	(void)other;
	std::cout << "Point values are const" << std::endl;
}