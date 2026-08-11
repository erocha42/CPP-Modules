#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : hit_point(10), energy_point(10), attack_damage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hit_point(10), energy_point(10), attack_damage(0)
{
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hit_point(other.hit_point), energy_point(other.energy_point), attack_damage(other.attack_damage)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->energy_point <= 0 || this->hit_point <= 0)
	{
		std::cout << "You do not have the necessary resources." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
	this->energy_point = this->energy_point - 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_point <= 0)
	{
		std::cout << "You do not have the necessary resources." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->name << " received " << amount << " points of damage!" << std::endl;
	this->hit_point = this->hit_point - amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_point <= 0 || this->hit_point <= 0)
	{
		std::cout << "You do not have the necessary resources." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->name << " has recovered " << amount << " health points!" << std::endl;
	this->hit_point = this->hit_point + amount;
	this->energy_point = this->energy_point - 1;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hit_point = other.hit_point;
		this->energy_point = other.energy_point;
		this->attack_damage = other.attack_damage;
	}
	return *this;
}