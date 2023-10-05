#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "[PhoneBook] Constructor called" << std::endl;
	this->_contactsIdx = 0;

	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "[PhoneBook] Destructor called" << std::endl;
	return ;
}

void	PhoneBook::addContact(void)
{
	this->_contacts[this->_contactsIdx].setContact();
	this->_contactsIdx++;
	if (this->_contactsIdx == 8)
		this->_contactsIdx = 0;
}

void	PhoneBook::displayContacts(void) const
{
	std::cout << "o-------------------------------------------o" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "|-------------------------------------------|" << std::endl;
		std::cout << "|" << std::setw(10) << i + 1;
		if (this->_contacts[i].firstName.size() > 9)
			std::cout << "|" << std::setw(9) << this->_contacts[i].firstName.substr(0, 9) << ".";
		else
			std::cout << "|" << std::setw(10) << this->_contacts[i].firstName;
		if (this->_contacts[i].lastName.size() > 9)
			std::cout << "|" << std::setw(9) << this->_contacts[i].lastName.substr(0, 9) << ".";
		else
			std::cout << "|" << std::setw(10) << this->_contacts[i].lastName;
		if (this->_contacts[i].nickname.size() > 9)
			std::cout << "|" << std::setw(9) << this->_contacts[i].nickname.substr(0, 9) << ".|" << std::endl;
		else
			std::cout << "|" << std::setw(10) << this->_contacts[i].nickname << "|" << std::endl;
	}
	std::cout << "o-------------------------------------------o" << std::endl;

	this->_displayDetails();
}

void	PhoneBook::_displayDetails(void) const
{
	std::string	idx;

	std::cout << "\nPick a contact to display:" << std::endl;

	std::cin >> idx;
	while (idx.size() != 1 || idx[0] < '1' || idx[0] > '8')
	{
		std::cout << "Please input a number between 1-8" << std::endl;
		std::cin >> idx;
	}

	std::cout << "First Name: " << this->_contacts[idx[0] - 49].firstName << std::endl;
	std::cout << "Last Name: " << this->_contacts[idx[0] - 49].lastName << std::endl;
	std::cout << "Nickname: " << this->_contacts[idx[0] - 49].nickname << std::endl;
	std::cout << "Phone Number: " << this->_contacts[idx[0] - 49].phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->_contacts[idx[0] - 49].getDarkestSecret() << std::endl;
}
