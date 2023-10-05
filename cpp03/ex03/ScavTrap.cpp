#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "[blank] " << "ScavTrap constructor called" << std::endl;
	this->_name = "blank";
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "[" << name << "] " << "ScavTrap constructor called" << std::endl;
	this->_name = name;
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	std::cout << "[" << src.getName() << "] " << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "[" << this->_name << "] " << "ScavTrap destructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(ScavTrap const & rhs)
{
	this->_name = rhs.getName();
	this->_hp = rhs.getHp();
	this->_ep = rhs.getEp();
	this->_ad = rhs.getAd();
	return *this;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_hp > 0 && this->_ep > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target
		<< " dealing " << this->_ad << " attack damage!" << std::endl;
		this->_ep -= 1;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " has entered Gate keeper mode!" << std::endl;
}
