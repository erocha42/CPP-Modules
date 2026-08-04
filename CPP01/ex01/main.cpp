#include "Zombie.hpp"

int	main()
{
	Zombie*	zs;
	int		n;

	n = 5;
	zs = zombieHorde(0, "Zero");
	zs = zombieHorde(n, "Zzz");
	for (int i = 0; i < n; i++)
		zs[i].announce();
	delete[] zs;
	return (0);
}