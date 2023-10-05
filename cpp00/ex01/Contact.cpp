#include <iostream>
#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "[Contact] Constructor called" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	std::cout << "[Contact] Destructor called" << std::endl;
	return ;
}

void	Contact::setContact(void)
{
	this->firstName = _getInput("First Name");
	this->lastName = _getInput("Last Name");
	this->nickname = _getInput("Nickname");
	this->phoneNumber = _getInput("Number");
	this->_darkestSecret = _getInput("Darkest Secret");
}

std::string	Contact::getDarkestSecret(void) const
{
	return (this->_darkestSecret);
}

std::string	Contact::_getInput(std::string type) const
{
	std::string	input;

	std::cout << "Enter the contact's " << type << std::endl;
	std::cin >> input;

	if (!type.compare("Number"))
		while (!_isValidNumber(input))
			std::cin >> input;
	
	return (input);
}

bool	Contact::_isValidNumber(std::string input) const
{
	for (int i = 0; input[i]; i++)
	{
		if (!isdigit(input[i]))
		{
			std::cout << "Wrong number format." << std::endl;
			return (false);
		}
	}

	return (true);
}
