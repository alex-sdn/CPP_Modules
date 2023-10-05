#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class AAnimal {

	public :

		AAnimal();
		AAnimal(AAnimal const & src);
		AAnimal&	operator=(AAnimal const & rhs);
		virtual ~AAnimal();

		std::string		getType() const;

		virtual void	makeSound() const = 0;

	protected :

		std::string	_type;
	
};

#endif
