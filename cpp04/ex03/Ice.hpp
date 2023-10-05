#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {

	public :

		Ice();
		Ice(Ice const & src);
		Ice&	operator=(Ice const & rhs);
		~Ice();

		virtual AMateria*	clone() const;

};

#endif