#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include <stdint.h>

typedef struct s_data {
	int			n;
	float		f;
	char		c;
	std::string	str;
}			Data;

class Serializer {

	public :

		static uintptr_t	serialize(Data *ptr);
		static Data*		deserialize(uintptr_t raw);
	
	private :

		Serializer();
		Serializer(Serializer const & src);
		Serializer& operator=(Serializer const & rhs);
		~Serializer();

};

#endif