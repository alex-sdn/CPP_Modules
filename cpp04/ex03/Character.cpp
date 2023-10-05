#include "Character.hpp"
#include <iostream>

Character::Character(std::string name) : _name(name)
{
	std::cout << "Character constructor called (" << name << ")" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const & src)
{
	this->_name = src.getName();
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = src._inventory[i];
}

Character&	Character::operator=(Character const & rhs)
{
	this->_name = rhs.getName();
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = rhs._inventory[i];
	return *this;
}

Character::~Character(void)
{
	std::cout << "Character destructor called (" << _name << ")" << std::endl;
}

std::string const &	Character::getName(void) const
{
	return this->_name;
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		this->_inventory[idx] = NULL;
	return ;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
	{
		this->_inventory[idx]->use(target);
		this->_inventory[idx] = NULL;
	}
}
