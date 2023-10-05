#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria constructor called (" << type << ")" << std::endl;
}

AMateria::AMateria(AMateria const & src)
{
	*this = src;
}

AMateria&	AMateria::operator=(AMateria const & rhs)
{
	this->_type = rhs.getType();
	return *this;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called (" << _type << ")" << std::endl;
}

std::string const &	AMateria::getType(void) const
{
	return this->_type;
}

void	AMateria::use(ICharacter& target)
{
	if (this->_type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (this->_type == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
