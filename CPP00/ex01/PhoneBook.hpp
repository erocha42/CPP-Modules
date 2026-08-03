#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

class	PhoneBook 
{
	Contact	contacts[8];
	int		index;

	public:
		PhoneBook() : index(0) {};
		void	add();
		void	search();
};

#endif