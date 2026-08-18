#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "-----Mandatory Animal tests-----" << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << meta->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
	}
	std::cout << std::endl << "-----OCF Animal tests-----" << std::endl;
	{
		const Animal i;
		const Animal ic(i);
		Animal j;
		const Cat k;
		const Cat kc(k);
		Cat l;
		const Dog m;
		const Dog mc(m);
		Dog n;
		j = i;
		l = k;
		n = m;
		std::cout << i.getType() << " " << std::endl;
		std::cout << j.getType() << " " << std::endl;
		std::cout << k.getType() << " " << std::endl;
		std::cout << l.getType() << " " << std::endl;
		std::cout << m.getType() << " " << std::endl;
		std::cout << n.getType() << " " << std::endl;
		std::cout << ic.getType() << " " << std::endl;
		std::cout << kc.getType() << " " << std::endl;
		std::cout << mc.getType() << " " << std::endl;
	}
	std::cout << std::endl << "-----WrongAnimal tests-----" << std::endl;
	{
		const WrongAnimal* wrong_meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;
		std::cout << wrong_meta->getType() << " " << std::endl;
		i->makeSound();
		wrong_meta->makeSound();
		delete wrong_meta;
		delete i;
	}
	return 0;
}