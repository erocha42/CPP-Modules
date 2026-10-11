#pragma once

#include "AForm.hpp"
#include <iostream>
#include <string>
#include <exception>

class	Bureaucrat
{
	const std::string	name;
	unsigned int		grade;

	public:
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		Bureaucrat(void);
		Bureaucrat(std::string const& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat(void);
		std::string		getName(void) const;
		unsigned int	getGrade(void) const;
		void			incrementGrade(void);
		void			decrementGrade(void);
		void			signForm(AForm& f);
		void			executeForm(AForm const& form) const;
		Bureaucrat&		operator=(const Bureaucrat& other);
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& value);