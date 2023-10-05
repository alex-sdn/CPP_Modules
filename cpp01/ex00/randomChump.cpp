#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	myZombie;

	myZombie.setName(name);
	myZombie.announce();

	return ;
}
