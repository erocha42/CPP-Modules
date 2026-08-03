#include "PhoneBook.hpp"

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

void	PhoneBook::add()
{
	int	i;
	std::string	input;

	i = index % 8;
	std::cout << "first name : ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(0);
	empty_field_handling(input);
	contacts[i].setFirstName(input);
	std::cout << "last name : ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(0);
	empty_field_handling(input);
	contacts[i].setLastName(input);
	std::cout << "nick name : ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(0);
	empty_field_handling(input);
	contacts[i].setNickName(input);
	std::cout << "phone number : ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(0);
	empty_field_handling(input);
	contacts[i].setPhoneNumber(input);
	std::cout << "darkest secret : ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(0);
	empty_field_handling(input);
	contacts[i].setDarkestSecret(input);
	index++;
}

void	PhoneBook::search()
{
	std::string	input;
	int			n;

	for (int i = 0; i < index && i < 8; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncate(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << truncate(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << truncate(contacts[i].getNickName()) << "|";
		std::cout << std::endl;
	}
	if (index == 0)
		return ;
	std::cout << "Enter an index : ";
	std::getline(std::cin, input);
	if (input.empty() || !is_only_digits(input))
		return ;
	n = std::atoi(input.c_str());
	if (n < 0 || n >= index || n >= 8)
		return ;
	std::cout << "First name     : " << contacts[n].getFirstName() << std::endl;
	std::cout << "Last name      : " << contacts[n].getLastName() << std::endl;
	std::cout << "Nick name      : " << contacts[n].getNickName() << std::endl;
	std::cout << "Phone number   : " << contacts[n].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret : " << contacts[n].getDarkestSecret() << std::endl;
}
