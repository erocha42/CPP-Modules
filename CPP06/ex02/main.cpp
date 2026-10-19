#include "Base.hpp"

Base	*generate(void)
{
	srand(time(NULL));
	switch (rand() % 3)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			return NULL;
	}
}

void	identify(Base *p)
{
	if (NULL != dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (NULL != dynamic_cast<B*>(p))
		std::cout << "B\n"; 
	else if (NULL != dynamic_cast<C*>(p))
		std::cout << "C\n";
}

void	identify(Base& p)
{
	try
	{
		A& a_ref = dynamic_cast<A&>(p);
		(void) a_ref;
		std::cout << "A\n";
		return ;
	}
	catch (const std::exception& e) {}
	try
	{
		B& b_ref = dynamic_cast<B&>(p);
		(void) b_ref;
		std::cout << "B\n"; 
		return ;
	}
	catch (const std::exception& e) {}
	try
	{
		C& a_ref = dynamic_cast<C&>(p);
		(void) a_ref;
		std::cout << "C\n";
	}
	catch (const std::exception& e) 
	{
		std::cout << e.what() << "\n";
	}
}

int	main()
{
	Base	*First;
	A		AFirst;
	B		BFirst;
	C 		CFirst;

	First = generate();
	identify(First);
	identify(AFirst);
	identify(BFirst);
	identify(CFirst);
	delete First;
}