#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Miaow" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	Animal::operator=(other);
	std::cout << "Cat copy assignment called" << std::endl;
	return	*this;
}