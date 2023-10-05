#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie*	myZombie = new Zombie();

	myZombie->setName(name);

	return myZombie;
}