#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed aX = a.getFixedX();
	Fixed aY = a.getFixedY();
	Fixed bX = b.getFixedX();
	Fixed bY = b.getFixedY();
	Fixed cX = c.getFixedX();
	Fixed cY = c.getFixedY();
	Fixed pX = point.getFixedX();
	Fixed pY = point.getFixedY();
	Fixed ab[2];
	ab[0] = bX - aX;
	ab[1] = bY - aY;
	Fixed ap[2];
	ap[0] = pX - aX;
	ap[1] = pY - aY;
	Fixed bc[2];
	bc[0] = cX - bX;
	bc[1] = cY - bY;
	Fixed bp[2];
	bp[0] = pX - bX;
	bp[1] = pY - bY;
	Fixed ca[2];
	ca[0] = aX - cX;
	ca[1] = aY - cY;
	Fixed cp[2];
	cp[0] = pX - cX;
	cp[1] = pY - cY;
	Fixed D1 = ((ab[0] * ap[1]) - (ab[1] * ap[0]));
	Fixed D2 = ((bc[0] * bp[1]) - (bc[1] * bp[0]));
	Fixed D3 = ((ca[0] * cp[1]) - (ca[1] * cp[0]));
	return ((D1 > 0 && D2 > 0 && D3 > 0) || (D1 < 0 && D2 < 0 && D3 < 0));
}
