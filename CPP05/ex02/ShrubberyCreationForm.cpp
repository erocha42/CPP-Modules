#include "ShrubberyCreationForm.hpp"
#include <fstream>

const char* ShrubberyCreationForm::FileNotOpened::what() const throw()
{
	return "\033[31mFileNotOpened\033[0m";
}

ShrubberyCreationForm::ShrubberyCreationForm(void)
: AForm("ShrubberyCreationForm", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
: AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other), target(other.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void	ShrubberyCreationForm::execute(Bureaucrat const& b) const
{
	if (b.getGrade() > this->getGradeToExecute())
		throw ShrubberyCreationForm::GradeTooLowException();
	if (!this->getIsSign())
		throw ShrubberyCreationForm::FormNotSignedException();
	std::ofstream	outfile((target + "_shrubbery").c_str());
	if (!outfile.is_open())
		throw ShrubberyCreationForm::FileNotOpened();
	outfile << 
	"       ###\n" <<
	"      #o###\n" <<
	"    #####o###\n" <<
	"   #o#\\#|#/###\n" <<
	"    ###\\|/#o#\n" <<
	"     # }|{  #\n" <<
	"       }|{\n"
	<< std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) 
{
	AForm::operator=(other);
	return *this;
}