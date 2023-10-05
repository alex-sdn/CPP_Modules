#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {

	public :

		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string phoneNumber;

		Contact();
		~Contact();

		void		setContact();
		std::string	getDarkestSecret() const;

	private :

		std::string	_darkestSecret;

		std::string	_getInput(std::string type) const;
		bool		_isValidNumber(std::string input) const;
};

#endif