#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

class	Contact
{
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_number;
	std::string	darkest_secret;

	public:
		void		setFirstName(std::string str);
		void		setLastName(std::string str);
		void		setNickName(std::string str);
		void		setPhoneNumber(std::string str);
		void		setDarkestSecret(std::string str);
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickName();
		std::string	getPhoneNumber();
		std::string	getDarkestSecret();
};

class	Phonebook 
{
	Contact	contacts[8];
	int		index;

	public:
		Phonebook() : index(0) {}
		void	add();
		void	search();
};

int			is_only_digits(std::string str);
void		empty_field_handling(std::string& field);
std::string	truncate(std::string str);

#endif