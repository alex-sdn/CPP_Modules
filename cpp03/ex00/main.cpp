#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap	TestBot("TestBot");

	TestBot.attack("FakeTarget");
	TestBot.takeDamage(6);
	TestBot.beRepaired(3);
	TestBot.takeDamage(6);
	TestBot.takeDamage(6);
	TestBot.attack("NO_HP_TEST");
	TestBot.beRepaired(111);

	std::cout << std::endl;

	ClapTrap	EnergyTest("EnergyTest");
	EnergyTest.attack("target-1");
	EnergyTest.attack("target-2");
	EnergyTest.attack("target-3");
	EnergyTest.attack("target-4");
	EnergyTest.attack("target-5");
	EnergyTest.attack("target-6");
	EnergyTest.attack("target-7");
	EnergyTest.attack("target-8");
	EnergyTest.attack("target-9");
	EnergyTest.attack("target-10");
	EnergyTest.attack("target-11");
	EnergyTest.attack("target-12");

	return 0;
}
