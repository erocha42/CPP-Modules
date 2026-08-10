#include "Point.hpp"

int main( void ) 
{
	Point	a(0, 10);
	Point	b(0, 2);
	Point	c(10, 0);
	Point	pointA(1, 1);
	Point	pointB(0, 10);
	Point	pointC(1, 3);
	Point	pointD(10, 10);

	std::cout << bsp(a, b, c, pointA) << " <<<<<<<<<<<<<<<<<<" << std::endl;
	std::cout << bsp(a, b, c, pointB) << " <<<<<<<<<<<<<<<<<<" << std::endl;
	std::cout << bsp(a, b, c, pointC) << " <<<<<<<<<<<<<<<<<<" << std::endl;
	std::cout << bsp(a, b, c, pointD) << " <<<<<<<<<<<<<<<<<<" << std::endl;
}