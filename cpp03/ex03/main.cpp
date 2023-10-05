#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
	DiamondTrap	DiamTest("DIAMTEST");

	std::cout << std::endl;
	DiamTest.attack("target");
	DiamTest.guardGate();
	DiamTest.highFivesGuys();
	DiamTest.takeDamage(99);
	DiamTest.whoAmI();
	std::cout << std::endl;

	return 0;
}
