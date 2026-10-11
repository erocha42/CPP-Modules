#include "Intern.hpp"

const char*	Intern::FormUnknow::what() const throw()
{
	return "\033[31mFormUnknow\033[0m";
}

Intern::Intern(void) {}

Intern::~Intern(void) {}

static AForm* makePresidential(std::string const& target) {return new PresidentialPardonForm(target);}
static AForm* makeRobotomy(std::string const& target) {return new RobotomyRequestForm(target);}
static AForm* makeShrubbery(std::string const& target) {return new ShrubberyCreationForm(target);}

AForm*	Intern::makeForm(std::string const& formName, std::string const& target)
{
	std::string	forms[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm*	(*ptr[3])(std::string const&) =
	{
		&makePresidential,
		&makeRobotomy,
		&makeShrubbery
	};
	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return	ptr[i](target);
		}
	}
	std::cout << "Intern failed to create a form" << std::endl;
	throw FormUnknow();
}