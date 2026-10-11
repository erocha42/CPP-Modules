#pragma once

class Bureaucrat;
#include <iostream>
#include <string>
#include <exception>

class	AForm
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
		class	FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		AForm(void);
		AForm(std::string const& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		virtual ~AForm(void);
		std::string		getName() const;
		bool			getIsSign() const;
		unsigned int	getGradeToSign() const;
		unsigned int	getGradeToExecute() const;
		void			beSigned(Bureaucrat& b);
		virtual void	execute(Bureaucrat const& executor) const = 0;
		AForm&			operator=(const AForm& other);
};

std::ostream&	operator<<(std::ostream& out, const AForm& value);