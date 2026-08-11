#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("A");
	ClapTrap b;
	ClapTrap c(a);
	ClapTrap d;
	
	d = a;
	d.attack("X");
	for (int i = 0; i < 5; i++)
		a.attack("X");
	a.beRepaired(5);
	a.takeDamage(15);
	a.attack("X");
	for (int i = 0; i < 10; i++)
		c.attack("X");
	return 0;
}