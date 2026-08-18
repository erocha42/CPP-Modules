#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Waf" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	Animal::operator=(other);
	std::cout << "Dog copy assignment called" << std::endl;
	return	*this;
}