#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie*	test = newZombie("heapZombie");

	test->announce();

	randomChump("stackZombie");

	delete test;

	return 0;
}
