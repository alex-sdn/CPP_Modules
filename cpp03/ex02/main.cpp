#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap	ClapTest("CLAP");
	ScavTrap	ScavTest("SCAV");
	FragTrap	FragTest("FRAG");

	std::cout << std::endl;

	ClapTest.attack("target");
	ScavTest.attack("target");
	FragTest.attack("target");
	
	std::cout << std::endl;

	ClapTest.takeDamage(90);
	ScavTest.takeDamage(90);
	FragTest.takeDamage(90);

	std::cout << std::endl;

	ClapTest.beRepaired(10);
	ScavTest.beRepaired(10);
	FragTest.beRepaired(10);

	std::cout << std::endl;

	ScavTest.guardGate();
	FragTest.highFivesGuys();

	std::cout << std::endl;

	return 0;
}
