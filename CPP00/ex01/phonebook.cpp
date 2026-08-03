#include "phonebook.hpp"

void	Contact::setFirstName(std::string str) { this->first_name = str; }
void	Contact::setLastName(std::string str) { this->last_name = str; }
void	Contact::setNickName(std::string str) { this->nick_name = str; }
void	Contact::setPhoneNumber(std::string str) { this->phone_number = str; }
void	Contact::setDarkestSecret(std::string str) { this->darkest_secret = str; }
std::string	Contact::getFirstName() { return this->first_name; }
std::string	Contact::getLastName() { return this->last_name; }
std::string	Contact::getNickName() { return this->nick_name; }
std::string	Contact::getPhoneNumber() { return this->phone_number; }
std::string	Contact::getDarkestSecret() { return this->darkest_secret; }

void	Phonebook::add()
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

void	Phonebook::search()
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

int	main()
{
	std::string	input;
	Phonebook	phonebook;

	while (1)
	{
		std::cout << "Enter an argument (ADD, SEARCH, EXIT) : ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (0);
		if (input == "ADD")
			phonebook.add();
		if (input == "SEARCH")
			phonebook.search();
		if (input == "EXIT")
			return (0);
	}
	return (1);
}
