#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	ScavTrap TestScav("TestScav");

	std::cout << std::endl;

	TestScav.attack("target");
	TestScav.takeDamage(99);
	TestScav.beRepaired(101);
	TestScav.guardGate();
	
	std::cout << std::endl;

	return 0;
}
