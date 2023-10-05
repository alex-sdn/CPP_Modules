#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(Cure const & src) : AMateria("cure")
{
	*this = src;
}

Cure&	Cure::operator=(Cure const & rhs)
{
	(void)rhs;
	return *this;
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
}

AMateria*	Cure::clone(void) const
{
	AMateria* clone = new Cure(*this);

	return clone;
}
