#include "Zombie.hpp"

int	main()
{
	Zombie*	z;
	std::cout << "---Scope start---" << std::endl;
	{
		Zombie	b("b");
		z = newZombie("z");
		b.announce();
		z->announce();
	}
	std::cout << "---Scope end---" << std::endl;
	std::cout << "randomChump :" << std::endl;
	randomChump("Zzzz");
	delete z;
	return (0);
}