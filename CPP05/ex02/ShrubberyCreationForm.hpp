#pragma once

#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class	ShrubberyCreationForm : public AForm
{
	std::string	const target;

	public:
		class	FileNotOpened : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string const& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm(void);
		void					execute(Bureaucrat const& executor) const;
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
};