#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public AForm {

	public :

		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		PresidentialPardonForm&	operator=(PresidentialPardonForm const & rhs);
		~PresidentialPardonForm();

		virtual std::string		getTarget() const;

		virtual void			execute(Bureaucrat const & executor) const;

	private :

		std::string		_target;

};

#endif