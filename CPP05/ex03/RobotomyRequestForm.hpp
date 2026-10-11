#pragma once

#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class	RobotomyRequestForm : public AForm
{
	std::string	const target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		~RobotomyRequestForm(void);
		void					execute(Bureaucrat const& executor) const;
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);
};