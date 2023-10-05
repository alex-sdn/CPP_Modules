#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {

	public :

		PhoneBook();
		~PhoneBook();

		void	addContact();
		void	displayContacts() const;

	private :

		int		_contactsIdx;
		Contact	_contacts[8];

		void	_displayDetails() const;

};

#endif