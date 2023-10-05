#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal {

	public :

		WrongAnimal();
		WrongAnimal(WrongAnimal const & src);
		WrongAnimal&	operator=(WrongAnimal const & rhs);
		~WrongAnimal();  // missing 'virtual'

		std::string		getType() const;

		virtual void	makeSound() const;

	protected :

		std::string	_type;

};

#endif
