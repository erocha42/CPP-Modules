#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB(void) {}

void HumanB::setWeapon(Weapon& newWeapon)
{
	this->weapon = &newWeapon;
}

void	HumanB::attack()
{
	if (weapon == NULL)
	{
		std::cout << name << " attacks with their hand" << std::endl;
		return ;
	}
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}