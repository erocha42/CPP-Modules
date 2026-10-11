#pragma once

#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class	Intern
{
	public:
		class	FormUnknow : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		Intern(void);
		~Intern(void);
		AForm*	makeForm(std::string const& formName, std::string const& target);
};