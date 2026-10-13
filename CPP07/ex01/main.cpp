#include "iter.hpp"

#include <iostream>
#include <string>

void	printstrs(std::string const& str)
{
	std::cout << str << "\n";
}

void	modStr(std::string& str)
{
	str = "mod";
}

template <typename T>
void	printAnything(T const& v)
{
	std::cout << v << "\n";
}

int	main()
{
	std::string	strs[] = {"un", "deux"};
	const int	ints[] = {1, 2};

	::iter(strs, 2, printstrs);
	::iter(strs, 2, modStr);	
	::iter(ints, 2, printAnything<int>);
	::iter(strs, 2, printAnything<std::string>);
}