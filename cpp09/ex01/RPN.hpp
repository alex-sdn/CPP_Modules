#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>
# include <list>

class RPN {

	public :

		RPN(std::string expression);
		RPN(RPN const & src);
		RPN&	operator=(RPN const & rhs);
		~RPN();

		std::string		getExpression() const;
		void			calculate();

		class	InvalidCharacterException : public std::exception {
			public :
				virtual const char* what() const throw();
		};
		class	WrongTokenCount : public std::exception {
			public :
				virtual const char* what() const throw();
		};
		class	DivisionByZero : public std::exception {
			public :
				virtual const char* what() const throw();
		};

	private :

		RPN();
		void			_checkFormat() const;
		void			_sum(std::stack<int, std::list<int> > &stk);
		void			_sub(std::stack<int, std::list<int> > &stk);
		void			_div(std::stack<int, std::list<int> > &stk);
		void			_mult(std::stack<int, std::list<int> > &stk);

		std::string		_expression;

};

#endif