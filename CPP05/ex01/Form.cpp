#include "Form.hpp"
#include "Bureaucrat.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
	return "\033[31mGradeTooHighException\033[0m";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "\033[31mGradeTooLowException\033[0m";
}

Form::Form(void) : name(""), isSign(false), gradeToSign(150), gradeToExecute(150) {}

Form::Form(std::string const& name, int gradeToSign, int gradeToExecute)
: name(name), isSign(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) 
{
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
}

Form::Form(const Form& other) : name(other.name), isSign(other.isSign), gradeToSign(other.gradeToSign), 
gradeToExecute(other.gradeToExecute) {}

Form::~Form(void) {}

std::string	Form::getName(void) const {return this->name;}

bool	Form::getIsSign(void) const {return this->isSign;}

unsigned int	Form::getGradeToSign(void) const {return this->gradeToSign;}

unsigned int	Form::getGradeToExecute(void) const {return this->gradeToExecute;}

void	Form::beSigned(Bureaucrat& b)
{
	if (this->gradeToSign >= b.getGrade())
		this->isSign = true;
	else
		throw GradeTooLowException();
}

Form&	Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->isSign = other.isSign;
	}
	return	*this;
}

std::ostream&	operator<<(std::ostream& out, const Form& form)
{
	out << form.getName() << (form.getIsSign() ? " signed " : " is not sign ") << "and must have " 
	<< form.getGradeToSign() << " of grade to sign and " << form.getGradeToExecute() << " of grade to execute";
	return out;
}