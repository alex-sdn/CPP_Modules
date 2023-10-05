#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

	public :

		MateriaSource();
		MateriaSource(MateriaSource const & src);
		MateriaSource&	operator=(MateriaSource const & rhs);
		~MateriaSource();

		virtual void 		learnMateria(AMateria* m);
		virtual AMateria*	createMateria(std::string const & type);
	
	private :

		AMateria*	_materias[4];

};

#endif