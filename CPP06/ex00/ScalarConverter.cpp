#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const& other) {(void)other;}

ScalarConverter::~ScalarConverter() {}

ScalarConverter&	ScalarConverter::operator=(ScalarConverter const& other) 
{
	(void)other;
	return *this;
}

enum sctypes
{
	ISINT,
	ISDECIMAL,
	ISCHAR,
	NONE
};

static int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

static int	ft_isprint(char c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}

static	void decimalDisplayHandling(double d, int precision_n)
{
	if (std::floor(d) == d)
	{
		std::cout.precision(1);
		std::cout << std::fixed;
	}
	else
		std::cout.precision(precision_n);
}

static sctypes	typer(std::string const&	str)
{
	int	i;
	int	dot_counter;

	i = 0;
	dot_counter = 0;
	if (ft_isprint(str[i]) && !ft_isdigit(str[i]) && !str[i + 1])
		return ISCHAR;
	if (str[i + 1] && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i] && (ft_isdigit(str[i]) || str[i] == '.'))
	{
		if (str[i] == '.')
		{
			if ((i > 0 && !ft_isdigit(str[i - 1])) || dot_counter == 1 
				|| i == 0 || str[i + 1] == 'f' || !str[i + 1])
				return NONE;
			dot_counter++;
		}
		i++;
	}
	if (str[i] == 'f' && dot_counter && !str[i + 1])
		return ISDECIMAL;
	if (dot_counter && !str[i])
		return ISDECIMAL;
	if (!str[i])
		return ISINT;
	return NONE;
}

static void charSConverter(std::string const& str)
{
	std::cout <<
	"char: '" << str[0] << "'\n";
	std::cout.precision(1);
	std::cout << std::fixed <<
	"int: " << static_cast<int>(str[0]) << "\n" <<
	"float: " << static_cast<float>(str[0]) << "f\n" <<
	"double: " << static_cast<double>(str[0]) << "\n";
}

static void intSConverter(std::string const& str)
{
	errno = 0;
	long	l = strtol(str.c_str(), NULL, 10);

	if (l >= 32 && l <= 126)
		std::cout << "char: '" << static_cast<char>(l) << "'\n";
	else if (l >= 0 && l <= 127)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: impossible\n";
	std::cout.precision(1);
	std::cout << std::fixed;
	if (errno != ERANGE && l >= INT_MIN && l <= INT_MAX)
		std::cout << "int: " << static_cast<int>(l) << "\n";
	else
		std::cout << "int: impossible\n";
	if (errno != ERANGE && l >= -FLT_MAX && l <= FLT_MAX)
		std::cout << "float: " << static_cast<float>(l) << "f\n";
	else
		std::cout << "float: impossible\n";
	if (errno != ERANGE && l >= -DBL_MAX && l <= DBL_MAX)
		std::cout << "double: " << static_cast<double>(l) << "\n";
	else
		std::cout << "double: impossible\n";
}

static void	decimalSConverter(std::string const& str)
{
	errno = 0;
	double	d = strtod(str.c_str(), NULL);

	if (d >= 32 && d < 127)
		std::cout << "char: '" << static_cast<char>(d) << "'\n";
	else if (d > -1 && d < 128)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: impossible\n";
	if (errno != ERANGE && d >= INT_MIN && d <= INT_MAX)
		std::cout << "int: " << static_cast<int>(d) << "\n";
	else
		std::cout << "int: impossible\n";
	decimalDisplayHandling(d, 6);
	if (errno != ERANGE &&	 d >= -FLT_MAX && d <= FLT_MAX)
		std::cout << "float: " << static_cast<float>(d) << "f\n";
	else
		std::cout << "float: impossible\n";
	decimalDisplayHandling(d, 15);
	if (errno != ERANGE)
		std::cout << "double: " << d << "\n";
	else
		std::cout << "double: impossible\n";
}

void	ScalarConverter::convert(std::string const&	str)
{
	if (str.empty())
	{
		std::cout << "Error: empty string" << "\n";
		return ;
	}
	if (str == "nan" || str == "-inf" || str == "+inf")
	{
		std::cout <<
		"char: impossible\n" <<
		"int: impossible\n" <<
		"float: " << str << "f\n" <<
		"double: " << str << "\n";
		return ;
	}
	if (str == "nanf" || str == "+inff" || str == "-inff")
	{
		std::cout <<
		"char: impossible\n" <<
		"int: impossible\n" <<
		"float: " << str << "\n" <<
		"double: " << str.substr(0, str.size() - 1) << "\n";
		return ;
	}
	switch (typer(str))
	{
		case ISINT:
			intSConverter(str);
			break;
		case ISCHAR:
			charSConverter(str);
			break;
		case ISDECIMAL:
			decimalSConverter(str);
			break;
		default:
			std::cout << "Error: input is invalid\n";
			break;
	}
}
