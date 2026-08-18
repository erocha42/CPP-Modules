#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*other.brain);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

Brain*	Cat::getBrain(void) const {return this->brain;}

void	Cat::makeSound(void) const
{
	std::cout << "Miaow" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	Animal::operator=(other);
	*this->brain = *other.brain;
	std::cout << "Cat copy assignment called" << std::endl;
	return	*this;
}