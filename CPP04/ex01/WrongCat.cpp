#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Miaow" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	WrongAnimal::operator=(other);
	std::cout << "WrongCat copy assignment called" << std::endl;
	return	*this;
}