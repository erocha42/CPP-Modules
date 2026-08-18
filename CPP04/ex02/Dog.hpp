#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class	Dog : public Animal
{
	private:
		Brain*	brain;

	public:
		Dog(void);
		Dog(const Dog& other);
		~Dog(void);
		Brain*	getBrain(void) const;
		void	makeSound(void) const;
		Dog&	operator=(const Dog& other);
};

#endif