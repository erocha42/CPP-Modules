#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

const std::string&	Brain::getAnIdea(int index) const
{
	static std::string	null_str = "";

	if (index < 0 || index > 99)
		return	null_str;
	return this->ideas[index];
}

void	Brain::setAnIdea(int index, const std::string& newString)
{
	if (index >= 0 && index <= 99)
		this->ideas[index] = newString;
}

Brain&	Brain::operator=(const Brain& other)
{
	std::cout << "Brain copy assignment called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}