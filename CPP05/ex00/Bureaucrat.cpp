#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "\033[31mGradeTooHighException\033[0m";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "\033[31mGradeTooLowException\033[0m";
}

Bureaucrat::Bureaucrat(void) : name(""), grade(150) {}

Bureaucrat::Bureaucrat(std::string const& name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat::~Bureaucrat(void) {}

std::string	Bureaucrat::getName(void) const {return this->name;}

unsigned int Bureaucrat::getGrade(void) const {return this->grade;}

void	Bureaucrat::incrementGrade(void)
{
	if (((int)this->grade - 1) < 1)
		throw GradeTooHighException();
	else
		this->grade -= 1;
}

void	Bureaucrat::decrementGrade(void)
{
	if (((int)this->grade + 1) > 150)
		throw GradeTooLowException();
	else
		this->grade += 1;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return	*this;
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}