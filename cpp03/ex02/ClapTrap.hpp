#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {

	public :

		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap();

		ClapTrap&	operator=(ClapTrap const & rhs);

		std::string	getName() const;
		int			getHp() const;
		int			getEp() const;
		int			getAd() const;

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	protected :

		std::string	_name;
		int			_hp;
		int			_ep;
		int			_ad;

};

#endif
