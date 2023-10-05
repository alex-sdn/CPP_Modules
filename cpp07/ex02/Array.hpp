#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array {

	public : 

		Array() : _array(new T()), _size(0) {}
		Array(unsigned int n) : _array(new T[n]), _size(n) {}
		Array(Array const & src) : _array(new T[src.size()]), _size(src.size()) {
			for (unsigned int i = 0; i < src.size(); i++)
				_array[i] = src._array[i];
		}
		Array&	operator=(Array const & rhs) {
			delete [] _array;
			_array = new T[rhs.size()];
			_size = rhs.size();
			for (unsigned int i = 0; i < rhs.size(); i++)
				_array[i] = rhs._array[i];
			return *this;
		}
		~Array() { delete [] _array; }

		class IndexTooHighException : public std::exception {
			public :
				virtual const char* what() const throw() {
					return ("Index too high.");
				}
		};

		T&	operator[](unsigned int i) {
			if (i >= size())
				throw IndexTooHighException();
			return _array[i];
		}

		unsigned int	size() const {
			return _size;
		}

	private :

		T*				_array;
		unsigned int	_size;

};

#endif