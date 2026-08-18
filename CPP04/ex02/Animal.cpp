#include "Animal.hpp"

Animal::Animal(void) : type("Animal default type")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string	Animal::getType(void) const
{
	return this->type;
}

void	Animal::makeSound(void) const {}

Animal&	Animal::operator=(const Animal& other)
{
	std::cout << "Animal copy assignment called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return	*this;
}