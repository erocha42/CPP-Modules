#include "phonebook.hpp"

int	is_only_digits(std::string str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	empty_field_handling(std::string& field)
{
	while (field.empty())
	{
		if (std::cin.eof())
			exit(0);
		std::cout << "This field must not be empty, retry : " << std::endl;
		std::getline(std::cin, field);
	}
}

std::string	truncate(std::string str)
{
	if (str.size() > 10)
		return (str.substr(0, 9) + ".");
	return	str;
}