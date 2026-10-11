#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void)
: AForm("RobotomyRequestForm", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
: AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other), target(other.target) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void	RobotomyRequestForm::execute(Bureaucrat const& b) const
{
	if (b.getGrade() > this->getGradeToExecute())
		throw RobotomyRequestForm::GradeTooLowException();
	if (!this->getIsSign())
		throw RobotomyRequestForm::FormNotSignedException();
	srand(time(NULL));
	std::cout << "Bzzzzz, " << target << " has " << ((rand() % 2) == 1
	? "been successfully robotomized !" : "not been robotomized..") << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other) 
{
	AForm::operator=(other);
	return *this;
}