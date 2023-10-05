#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "[blank] " << "FragTrap constructor called" << std::endl;
	this->_name = "blank";
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "[" << name << "] " << "FragTrap constructor called" << std::endl;
	this->_name = name;
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
}

FragTrap::FragTrap(FragTrap const & src)
{
	std::cout << "[" << src.getName() << "] " << "FragTrap copy constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void)
{
	std::cout << "[" << this->_name << "] " << "FragTrap destructor called" << std::endl;
}

FragTrap&	FragTrap::operator=(FragTrap const & rhs)
{
	this->_name = rhs.getName();
	this->_hp = rhs.getHp();
	this->_ep = rhs.getEp();
	this->_ad = rhs.getAd();
	return *this;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name
	<< " wants to high five you!" << std::endl;
}