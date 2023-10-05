#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {

	public :

		Cat();
		Cat(Cat const & src);
		Cat&	operator=(Cat const & rhs);
		~Cat();

		Brain*			getBrain() const;

		virtual void	makeSound() const;

	private :

		Brain*	_brain;

};

#endif