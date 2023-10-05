#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain {

	public :

		Brain();
		Brain(Brain const & src);
		Brain&	operator=(Brain const & rhs);
		~Brain();

	private :

		std::string	_ideas[100];

};

#endif