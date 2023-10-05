#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span {

	public :

		Span(unsigned int N);
		Span(Span const & src);
		Span&	operator=(Span const & rhs);
		~Span();

		unsigned int		getMaxSize() const;
		std::vector<int>	getSpan() const;

		void				addNumber(int n);
		void				insertNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int					shortestSpan();
		int					longestSpan();

		class	FullSpanException : public std::exception {
			public :
				virtual const char* what() const throw();
		};
		class	SpanTooSmallException : public std::exception {
			public :
				virtual const char* what() const throw();
		};
		
	private :
		
		Span();

		unsigned int		_maxSize;
		std::vector<int>	_span;

};


#endif