#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

	public :

		Fixed();
		Fixed(int const nbr);
		Fixed(float const nbr);
		Fixed(Fixed const & src);
		~Fixed();

		Fixed&	operator=(Fixed const & rhs);

		bool	operator<(Fixed const & rhs) const;
		bool	operator<=(Fixed const & rhs) const;
		bool	operator>(Fixed const & rhs) const;
		bool	operator>=(Fixed const & rhs) const;
		bool	operator==(Fixed const & rhs) const;
		bool	operator!=(Fixed const & rhs) const;

		Fixed	operator+(Fixed const & rhs) const;
		Fixed	operator-(Fixed const & rhs) const;
		Fixed	operator*(Fixed const & rhs) const;
		Fixed	operator/(Fixed const & rhs) const;

		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);

		static Fixed&			min(Fixed& a, Fixed& b);
		static const Fixed&		min(Fixed const & a, Fixed const & b);
		static Fixed&			max(Fixed& a, Fixed& b);
		static const Fixed&		max(Fixed const & a, Fixed const & b);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private :

		int					_rawBits;
		static const int	_nBits;

};

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs);

#endif
