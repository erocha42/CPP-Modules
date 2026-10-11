#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
	return "\033[31mGradeTooHighException\033[0m";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "\033[31mGradeTooLowException\033[0m";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "\033[31mFormNotSignedException\033[0m";
}

AForm::AForm(void) : name(""), isSign(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(std::string const& name, int gradeToSign, int gradeToExecute)
: name(name), isSign(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) 
{
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm& other) : name(other.name), isSign(other.isSign), gradeToSign(other.gradeToSign), 
gradeToExecute(other.gradeToExecute) {}

AForm::~AForm(void) {}

std::string	AForm::getName(void) const {return this->name;}

bool	AForm::getIsSign(void) const {return this->isSign;}

unsigned int	AForm::getGradeToSign(void) const {return this->gradeToSign;}

unsigned int	AForm::getGradeToExecute(void) const {return this->gradeToExecute;}

void	AForm::beSigned(Bureaucrat& b)
{
	if (this->gradeToSign >= b.getGrade())
		this->isSign = true;
	else
		throw GradeTooLowException();
}

AForm&	AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->isSign = other.isSign;
	}
	return	*this;
}

std::ostream&	operator<<(std::ostream& out, const AForm& form)
{
	out << form.getName() << (form.getIsSign() ? " signed " : " is not sign ") << "and must have " 
	<< form.getGradeToSign() << " of grade to sign and " << form.getGradeToExecute() << " of grade to execute";
	return out;
}