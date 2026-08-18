#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

class	WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(const WrongCat& other);
		~WrongCat(void);
		void	makeSound(void) const;
		WrongCat&	operator=(const WrongCat& other);
};

#endif