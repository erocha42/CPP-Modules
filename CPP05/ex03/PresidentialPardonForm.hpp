#pragma once

#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class	PresidentialPardonForm : public AForm
{
	std::string	const target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		~PresidentialPardonForm(void);
		void	execute(Bureaucrat const& executor) const;
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);
};