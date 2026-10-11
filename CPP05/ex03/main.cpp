#include "Intern.hpp"

struct	DataForm
{
	std::string	formName;
	std::string target;
	int			grade;
};

int	main(void)
{
	DataForm dataForm[] =
	{
		{"robotomy request", "Arthur", 1},
		{"shrubbery creation", "Ben", 1},
		{"presidential pardon", "Cesar", 1},
		{"Something else", "David", 1},
		{"", "Enzo", 1},
		{"robotomy request", "Franck", 140},
		{"presidential pardon", "Gaspar", 10},
		{"presidential pardon", "Hector", -5},
	};
	for (size_t i = 0; i < (sizeof(dataForm) / sizeof(dataForm[0])); i++)
	{
		try
		{
			Intern in;
			AForm* f;
			Bureaucrat	b("b", dataForm[i].grade);
			f = in.makeForm(dataForm[i].formName, dataForm[i].target);
			b.signForm(*f);
			b.executeForm(*f);
			std::cout << *f << std::endl;	
			delete f;
		}
		catch (const std::exception&	e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
		if (i < (sizeof(dataForm) / sizeof(dataForm[0])) - 1)
			std::cout << std::endl;
	}
	return 0;
}