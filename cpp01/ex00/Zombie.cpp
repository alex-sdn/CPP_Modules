#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) : _name("nameless")
{
}

Zombie::~Zombie(void)
{
	std::cout << "Destructor called for " << this->_name << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}
