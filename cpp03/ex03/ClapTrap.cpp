#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) : _name("blank"), _hp(10), _ep(10), _ad(0)
{
	std::cout << "[blank] " << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _ad(0)
{
	std::cout << "[" << name << "] " << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "[" << src.getName() << "] " << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "[" << this->_name << "] " << "ClapTrap destructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const & rhs)
{
	this->_name = rhs.getName();
	this->_hp = rhs.getHp();
	this->_ep = rhs.getEp();
	this->_ad = rhs.getAd();
	return *this;
}

std::string	ClapTrap::getName(void) const
{
	return this->_name;
}

int	ClapTrap::getHp(void) const
{
	return this->_hp;
}

int	ClapTrap::getEp(void) const
{
	return this->_ep;
}

int	ClapTrap::getAd(void) const
{
	return this->_ad;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hp > 0 && this->_ep > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target
		<< " causing " << this->_ad << " points of damage!" << std::endl;
		this->_ep -= 1;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hp -= amount;
	if (this->_hp < 0)
		this->_hp = 0;
	std::cout << "ClapTrap " << this->_name << " takes " << amount
	<< " points of damage, " << this->_hp << " HP remaining!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hp > 0 && this->_ep > 0)
	{
		std::cout << "ClapTrap " << this->_name
		<< " repairs himself and gains " << amount << " HP!" << std::endl;
		this->_hp += amount;
		this->_ep -= 1;
	}
}
