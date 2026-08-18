#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class	Brain
{
	private:
		std::string ideas[100];
	
	public:
		Brain(void);
		Brain(const Brain& other);
		~Brain(void);
		const std::string&	getAnIdea(int index) const;
		void	setAnIdea(int index, const std::string& newString);
		Brain&	operator=(const Brain& other);
};

#endif