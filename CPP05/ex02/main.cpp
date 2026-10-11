#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	intern("Intern", 150);

	ShrubberyCreationForm	shrubbery("home");
	RobotomyRequestForm		robotomy("Bender");
	PresidentialPardonForm	pardon("Marvin");

	AForm *	forms[3] = { &shrubbery, &robotomy, &pardon };

	std::cout << "--- required grades ---" << std::endl;
	for (int i = 0; i < 3; ++i)
		std::cout << *forms[i] << std::endl;

	std::cout << std::endl << "--- executing an unsigned form ---" << std::endl;
	boss.executeForm(shrubbery);

	std::cout << std::endl << "--- signing with a grade that is too low ---" << std::endl;
	intern.signForm(pardon);

	std::cout << std::endl << "--- signing then executing with a high enough grade ---" << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		boss.signForm(*forms[i]);
		boss.executeForm(*forms[i]);
	}

	std::cout << std::endl << "--- executing with a grade that is too low ---" << std::endl;
	intern.executeForm(pardon);

	return 0;
}