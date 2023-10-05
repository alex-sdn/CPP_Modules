#include "Fixed.hpp"

const int	Fixed::_nBits = 8;

Fixed::Fixed(void) : _rawBits(0)
{
	// Default constructor
}

Fixed::Fixed(Fixed const & src)
{
	// Copy constructor
	this->_rawBits = src.getRawBits();
}

Fixed::~Fixed(void)
{
	// Destructor
}

Fixed& Fixed::operator=(Fixed const & rhs)
{
	// Copy assignement operator
	this->_rawBits = rhs.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	return this->_rawBits;
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}
