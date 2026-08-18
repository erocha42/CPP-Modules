#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>

class	Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat& other);
		~Cat(void);
		void	makeSound(void) const;
		Cat&	operator=(const Cat& other);
};

#endif