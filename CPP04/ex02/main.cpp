#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << std::endl << "-----Mandatory Brain tests-----" << std::endl;
	{
		const Animal* j = new Dog;
		const Animal* i = new Cat;
		delete j;
		delete i;
	}
	std::cout << std::endl << "-----Loop Brain tests-----" << std::endl;
	{
		Animal*	animals[10];
		for (int i = 0; i < 10; i++)
		{
			if (i < 5)
				animals[i] = new Dog;
			else
				animals[i] = new Cat;
		}
		for (int i = 0; i < 10; i++)
			delete animals[i];
	}
	std::cout << std::endl << "-----Depth Brain tests-----" << std::endl;
	{
		Dog k;
		Dog l;
		k.getBrain()->setAnIdea(0, "Smart idea");
		l.getBrain()->setAnIdea(0, "Mega smart idea");
		std::cout << k.getBrain()->getAnIdea(0) << std::endl;
		std::cout << l.getBrain()->getAnIdea(0) << std::endl;
		std::cout << k.getBrain() << std::endl;
		std::cout << l.getBrain() << std::endl;
		k.getBrain()->setAnIdea(0, "New idea");
		std::cout << "After k copy l" << std::endl;
		k = l;
		std::cout << k.getBrain()->getAnIdea(0) << std::endl;
		std::cout << l.getBrain()->getAnIdea(0) << std::endl;
		std::cout << k.getBrain() << std::endl;
		std::cout << l.getBrain() << std::endl;
		std::cout << "m copy contructor test" << std::endl;
		Dog m(k);
		std::cout << k.getBrain()->getAnIdea(0) << std::endl;
		std::cout << l.getBrain()->getAnIdea(0) << std::endl;
		std::cout << m.getBrain()->getAnIdea(0) << std::endl;
		std::cout << k.getBrain() << std::endl;
		std::cout << l.getBrain() << std::endl;
		std::cout << m.getBrain() << std::endl;
	}
	//std::cout << std::endl << "-----Abstract class test-----" << std::endl;
	//{
	//	Animal a;

	//	a.makeSound();
	//}
	return 0;
}