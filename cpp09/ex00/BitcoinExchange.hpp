#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>

class BitcoinExchange {

	public :

		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const & src);
		BitcoinExchange& operator=(BitcoinExchange const & rhs);
		~BitcoinExchange();

		std::map<int, double>	getData() const;

		void				initData();
		void				getRates(char *infile);

		class	ValueTooSmall : public std::exception {
			public :
				virtual const char* what() const throw();
		};
		class	ValueTooBig : public std::exception {
			public :
				virtual const char* what() const throw();
		};
		class	ValueIncorrect : public std::exception {
			public :
				virtual const char* what() const throw();
		};
		class	WrongDateFormat : public std::exception {
			public :
				virtual const char* what() const throw();
		};
		class	WrongLineFormat : public std::exception {
			public :
				virtual const char* what() const throw();
		};
		class	DateTooEarly : public std::exception {
			public :
				virtual const char* what() const throw();
		};

	private :

		std::map<int, double>	_data;

		int					_convertDate(std::string date);
		double				_convertAmount(std::string amount);

};

#endif