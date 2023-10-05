#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int	main(void)
{
	int		hordeSize = 7;
	Zombie*	horde = zombieHorde(hordeSize, "Foo");

	for (int i = 0; i < hordeSize; i++)
		horde[i].announce();

	delete [] horde;

	return 0;
}
