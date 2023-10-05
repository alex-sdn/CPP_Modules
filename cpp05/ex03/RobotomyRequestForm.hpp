#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public AForm {

	public :

		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		RobotomyRequestForm&	operator=(RobotomyRequestForm const & rhs);
		~RobotomyRequestForm();

		virtual std::string		getTarget() const;

		virtual void			execute(Bureaucrat const & executor) const;

	private :

		std::string		_target;

};

#endif