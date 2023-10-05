#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <string>

class Bureaucrat;

class Form {

	public :

		Form(std::string name, int sign, int exec);
		Form(Form const & src);
		Form&	operator=(Form const & rhs);
		~Form();

		class GradeTooHighException : public std::exception {
			public :
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public :
				virtual const char* what() const throw();
		};

		std::string	getName() const;
		bool		getSigned() const;
		int			getSignMin() const;
		int			getExecMin() const;

		void		beSigned(Bureaucrat const & bureaucrat);

	private :

		std::string const	_name;
		bool				_signed;
		int	const			_signMin;
		int const			_execMin;

};

std::ostream &	operator<<(std::ostream & o, Form const & rhs);

#endif