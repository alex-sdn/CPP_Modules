#include "Fixed.hpp"
#include <cmath>

const int	Fixed::_nBits = 8;

Fixed::Fixed(void) : _rawBits(0)
{
	// Default constructor
}

Fixed::Fixed(int const nbr) : _rawBits(nbr << _nBits)
{
	// int constructor
}

Fixed::Fixed(float const nbr) : _rawBits((roundf)(nbr * (1 << _nBits)))
{
	// float constructor
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

Fixed&	Fixed::operator=(Fixed const & rhs)
{
	// Copy assignement operator
	this->_rawBits = rhs.getRawBits();
	return *this;
}

bool	Fixed::operator<(Fixed const & rhs) const
{
	if (this->_rawBits < rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<=(Fixed const & rhs) const
{
	if (this->_rawBits <= rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>(Fixed const & rhs) const
{
	if (this->_rawBits > rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>=(Fixed const & rhs) const
{
	if (this->_rawBits >= rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator==(Fixed const & rhs) const
{
	if (this->_rawBits == rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator!=(Fixed const & rhs) const
{
	if (this->_rawBits != rhs.getRawBits())
		return true;
	return false;
}

Fixed	Fixed::operator+(Fixed const & rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed const & rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(Fixed const & rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const & rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed&	Fixed::operator++(void)
{
	this->_rawBits++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	//post
	Fixed tmp = *this;
	this->operator++();
	return tmp;
}

Fixed&	Fixed::operator--(void)
{
	this->_rawBits--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	//post
	Fixed tmp = *this;
	this->operator--();
	return tmp;
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return b < a ? b : a;
}

const Fixed&	Fixed::min(Fixed const & a, Fixed const & b)
{
	return b < a ? b : a;
}
Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return b > a ? b : a;
}

const Fixed&	Fixed::max(Fixed const & a, Fixed const & b)
{
	return b > a ? b : a;
}


int	Fixed::getRawBits(void) const
{
	return this->_rawBits;
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)this->_rawBits / (1 << _nBits);
}

int	Fixed::toInt(void) const
{
	return this->_rawBits >> _nBits;
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}
