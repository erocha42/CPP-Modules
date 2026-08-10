#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

class	Point
{
	const Fixed	x;
	const Fixed	y;

	public:
		Point(void);
		Point(const Point& other);
		~Point(void);
		Point(Fixed x, Fixed y);
		const Fixed& getFixedX(void) const;
		const Fixed& getFixedY() const;
		void operator=(const Point& other);
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif