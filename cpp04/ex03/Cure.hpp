#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {

	public :

		Cure();
		Cure(Cure const & src);
		Cure&	operator=(Cure const & rhs);
		~Cure();

		virtual AMateria*	clone() const;

};

#endif