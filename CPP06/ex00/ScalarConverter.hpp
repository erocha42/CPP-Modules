#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cfloat>
#include <cerrno>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>

class	ScalarConverter
{
	ScalarConverter();
	ScalarConverter(ScalarConverter const& other);
	~ScalarConverter();
	ScalarConverter&	operator=(ScalarConverter const& other);
	public:
		static void	convert(std::string const& str);
};