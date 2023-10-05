#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <string>

class Bureaucrat;

class AForm {

	public :

		AForm(std::string name, int sign, int exec);
		AForm(AForm const & src);
		AForm&	operator=(AForm const & rhs);
		virtual ~AForm();

		class GradeTooHighException : public std::exception {
			public :
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public :
				virtual const char* what() const throw();
		};
		class FormUnsignedException : public std::exception {
			public :
				virtual const char* what() const throw();
		};

		std::string	getName() const;
		bool		getSigned() const;
		int			getSignMin() const;
		int			getExecMin() const;

		void			beSigned(Bureaucrat const & bureaucrat);
		virtual std::string		getTarget() const = 0;
		virtual void			execute(Bureaucrat const & executor) const = 0;

	private :

		std::string const	_name;
		bool				_signed;
		int	const			_signMin;
		int const			_execMin;

};

std::ostream &	operator<<(std::ostream & o, AForm const & rhs);

#endif