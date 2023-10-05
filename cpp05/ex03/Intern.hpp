#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {

	public :

		Intern();
		Intern(Intern const & src);
		Intern&	operator=(Intern const & rhs);
		~Intern();

		AForm*	makeForm(std::string type, std::string target);

	private :

		AForm*	_newShrubberyForm(std::string target);
		AForm*	_newRobotomyForm(std::string target);
		AForm*	_newPresidentialForm(std::string target);

};

#endif