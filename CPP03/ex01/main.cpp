#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	// Tests on ClapTrap
	{
		ClapTrap a0("A");
		ClapTrap b0;
		ClapTrap c0(a0);
		ClapTrap d0;
		
		d0 = a0;
		d0.attack("X");
		for (int i = 0; i < 5; i++)
			a0.attack("X");
		a0.beRepaired(5);
		a0.takeDamage(15);
		a0.attack("X");
		for (int i = 0; i < 10; i++)
			c0.attack("X");
	}

	std::cout << std::endl << std::endl;

	// Tests on ScavTrap
	{
		ScavTrap a1("A");
		ScavTrap b1;
		ScavTrap c1(a1);
		ScavTrap d1;
		
		d1 = a1;
		d1.attack("X");
		for (int i = 0; i < 5; i++)
			a1.attack("X");
		a1.beRepaired(5);
		a1.takeDamage(105);
		a1.attack("X");
		for (int i = 0; i < 10; i++)
			c1.attack("X");
		d1.guardGate();
	}
	return 0;
}