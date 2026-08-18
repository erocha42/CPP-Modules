#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class	WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& other);
		virtual ~WrongAnimal(void);
		std::string	getType(void) const;
		void	makeSound(void) const;
		WrongAnimal&	operator=(const WrongAnimal& other);
};

#endif