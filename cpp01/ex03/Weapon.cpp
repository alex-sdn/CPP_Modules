#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	// constructor
}

Weapon::~Weapon(void)
{
	// destructor
}

const std::string&	Weapon::getType(void) const
{
	return this->_type;
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
