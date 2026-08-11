#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap class default constructor called" << std::endl;
	this->hit_point = 100;
	this->energy_point = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "FragTrap class constructor called" << std::endl;
	this->hit_point = 100;
	this->energy_point = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap class copy constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap class destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void) const
{
	std::cout << "High five, everybody!" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (this->energy_point <= 0 || this->hit_point <= 0)
	{
		std::cout << "You do not have the necessary resources." << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
	this->energy_point = this->energy_point - 1;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	ClapTrap::operator=(other);
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	return *this;
}