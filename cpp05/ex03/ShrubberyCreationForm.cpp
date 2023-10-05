#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
	// constructor
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm("Shrubbery Creation Form", 145, 137)
{
	*this = src;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	_target = rhs.getTarget();
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	// destructor
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return _target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getSigned())
		throw AForm::FormUnsignedException();
	else if (executor.getGrade() > getExecMin())
		throw AForm::GradeTooLowException();
	else
	{
		std::ofstream	ofs;
		ofs.open((_target + "_shrubbery").c_str(), std::ofstream::out);
		if (!ofs.is_open())
		{
			std::cout << "Failed to open outfile." << std::endl;
			return ;
		}
		ofs << "               ,@@@@@@@," << std::endl << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl
		<< "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl
		<< "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl
		<< "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl << "       |o|        | |         | |" << std::endl
		<< "       |.|        | |         | |" << std::endl << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
		ofs.close();
	}
}
