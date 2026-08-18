#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain(*other.brain);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

Brain*	Dog::getBrain(void) const {return this->brain;}

void	Dog::makeSound(void) const
{
	std::cout << "Waf" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	Animal::operator=(other);
	*this->brain = *other.brain;
	std::cout << "Dog copy assignment called" << std::endl;
	return	*this;
}