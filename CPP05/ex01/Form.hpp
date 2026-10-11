#pragma once

class Bureaucrat;
#include <iostream>
#include <string>
#include <exception>

class	Form
{
	const std::string		name;
	bool					isSign;
	const unsigned int		gradeToSign;
	const unsigned int		gradeToExecute;

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
		Form(void);
		Form(std::string const& name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		~Form(void);
		std::string		getName() const;
		bool			getIsSign() const;
		unsigned int	getGradeToSign() const;
		unsigned int	getGradeToExecute() const;
		void			beSigned(Bureaucrat& b);
		Form&			operator=(const Form& other);
};

std::ostream&	operator<<(std::ostream& out, const Form& value);