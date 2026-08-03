#include "PhoneBook.hpp"

int	main()
{
	std::string	input;
	PhoneBook	phonebook;

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
