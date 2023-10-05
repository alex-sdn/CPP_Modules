#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include "Brain.hpp"

class WrongCat : public WrongAnimal {

	public :

		WrongCat();
		WrongCat(WrongCat const & src);
		WrongCat&	operator=(WrongCat const & rhs);
		~WrongCat();

		Brain*			getBrain() const;

		virtual void	makeSound() const;

	private :

		Brain*	_brain;

};

#endif
