#include <string>
#include <cstdlib>
#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
		return 1;
	ScalarConverter::convert(av[1]);
}