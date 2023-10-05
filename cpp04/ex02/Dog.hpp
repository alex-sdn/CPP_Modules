#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {

	public :

		Dog();
		Dog(Dog const & src);
		Dog&	operator=(Dog const & rhs);
		~Dog();

		Brain*			getBrain() const;

		virtual void	makeSound() const;

	private :

		Brain*	_brain;

};

#endif