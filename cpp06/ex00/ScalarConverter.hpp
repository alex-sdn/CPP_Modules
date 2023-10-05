#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

# define T_CHAR 0
# define T_INT 1
# define T_FLOAT 2
# define T_DOUBLE 3
# define T_MINF 4
# define T_PINF 5
# define T_NAN 6
# define T_WRONG 7

class ScalarConverter {

	public : 

		static void	convert(std::string arg);

	private :

		ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
		ScalarConverter& operator=(ScalarConverter const & rhs);
		~ScalarConverter();

		static int		_findType(std::string arg);
		static int		_checkInt(std::string arg);
		static int		_checkDouble(std::string arg);
		static int		_checkFloat(std::string arg);
		static float	_strToFloat(std::string& str);

		static void		_printChar(char c);
		static void		_printInt(int n);
		static void		_printFloat(float n);
		static void		_printDouble(double n);
		static void		_printMinf();
		static void		_printPinf();
		static void		_printNan();

};

#endif