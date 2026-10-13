#include "Array.hpp"
#include <iostream>

int main()
{
	int element = 5;
	Array<int> a(3);
	try
	{
		a[0] = 1;
		const Array<int> b(a);
		std::cout << b[0] << "\n";
	}
	catch (std::exception const& e)
	{
		std::cout << e.what() << "\n";
	}
	try
	{
		element = a[-1];
		std::cout << element << "\n";
	}
	catch (std::exception const& e)
	{
		std::cout << e.what() << "\n";
	}
	try
	{
		a[0] = 2;
		Array<int> b;
		b = a;
		Array<int> c(b);
		std::cout << b[0] << " " << c[0] << "\n";
		c[-1] = 3;
		std::cout << c[0] << "\n";
	}
	catch (std::exception const& e)
	{
		std::cout << e.what() << "\n";
	}
	try
	{
		Array<std::string> s(1);
		Array<std::string> sni;
		s[0] = "lol";
		std::cout << s[0] << "\n";
		sni[0] = "lol";
		std::cout << sni[0] << "\n";
	}
	catch (std::exception const& e)
	{
		std::cout << e.what() << "\n";
	}
}