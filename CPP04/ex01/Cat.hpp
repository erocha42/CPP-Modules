#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class	Cat : public Animal
{
	private:
		Brain*	brain;

	public:
		Cat(void);
		Cat(const Cat& other);
		~Cat(void);
		Brain*	getBrain(void) const;
		void	makeSound(void) const;
		Cat&	operator=(const Cat& other);
};

#endif