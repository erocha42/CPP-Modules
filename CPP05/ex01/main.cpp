#include "Bureaucrat.hpp"

struct	BureaucratTestCase
{
	const std::string 	testName;
	std::string 		name;
	const int			grade;
	const int			nb_upgrade;
	const int			nb_downgrade;
};

struct	FormTestCase
{
	const std::string	testName;
	std::string			name;
	bool				isSign;
	const unsigned int	gradeToSign;
	const unsigned int	gradeToExecute;
};

int	main(void)
{
	std::cout << "||||||||| BUREAUCRAT TESTS |||||||||" << std::endl << std::endl;
	BureaucratTestCase bTests[] =
	{
		// --- Simple construction ---
		{"Test 1 normal", "Alice", 75, 0, 0},
		{"Test 2 grade 0 (invalid, too high)", "Bob", 0, 0, 0},
		{"Test 3 negative grade (invalid, too high)", "Clark", -5, 0, 0},
		{"Test 4 grade 151 (invalid, too low)", "David", 151, 0, 0},
		{"Test 5 grade 1 (valid upper limit)", "Diana", 1, 0, 0},
		{"Test 6 grade 150 (valid lower limit)", "Dean", 150, 0, 0},

		// --- Simple increment ---
		{"Test 7 normal incrementGrade", "Enzo", 5, 1, 0},
		{"Test 8 incrementGrade from grade 1 (already at max)", "Frank", 1, 1, 0},
		{"Test 9 incrementGrade from grade 2", "Fiona", 2, 1, 0},

		// --- Simple decrement ---
		{"Test 10 normal decrementGrade", "Garfield", 100, 0, 1},
		{"Test 11 decrementGrade from grade 150 (already at min)", "Hank", 150, 0, 1},
		{"Test 12 decrementGrade from grade 149", "Iris", 149, 0, 1},

		// --- Already invalid construction + attempted operation ---
		{"Test 13 invalid construction (0) then incrementGrade", "James", 0, 1, 0},
		{"Test 14 invalid construction (151) then decrementGrade", "Karl", 151, 0, 1},

		// --- Multiple chained operations ---
		{"Test 15 several consecutive increments", "Laura", 10, 5, 0},
		{"Test 16 several consecutive decrements", "Marc", 140, 0, 5},
		{"Test 17 increments until exceeding the limit", "Nina", 3, 5, 0},
		{"Test 18 decrements until exceeding the limit", "Oscar", 147, 0, 5},

		// --- Increment then decrement (cancel out) ---
		{"Test 19 increment then decrement (back to original)", "Paul", 50, 1, 1},
	};
	for (size_t i = 0; i < (sizeof(bTests) / sizeof(bTests[0])); i++)
	{
		std::cout << "----- " << bTests[i].testName << " -----" << std::endl;
		try
		{
			Bureaucrat b(bTests[i].name, bTests[i].grade);
			for (int j = 0; j < bTests[i].nb_upgrade; j++)
				b.incrementGrade();
			for (int j = 0; j < bTests[i].nb_downgrade; j++)
				b.decrementGrade();
			std::cout << "\033[32mSuccess: " << b << "\033[0m" << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "\033[31m" << e.what() << "\033[0m" << std::endl;
		}
	}
	std::cout << std::endl << std::endl << "||||||||| FORM CONSTRUCTION TESTS |||||||||" << std::endl << std::endl;
	FormTestCase fTests[] =
	{
		// --- Simple valid construction ---
		{"Test 1 normal construction", "Tax Form", false, 50, 100},

		// --- Boundary values (valid) ---
		{"Test 2 sign=1 (valid upper limit)", "Elite Form", false, 1, 1},
		{"Test 3 sign=150, exec=150 (valid lower limit)", "Trivial Form", false, 150, 150},

		// --- gradeToSign out of bounds ---
		{"Test 4 gradeToSign=0 (invalid, too high)", "Broken Form A", false, 0, 50},
		{"Test 5 gradeToSign=151 (invalid, too low)", "Broken Form B", false, 151, 50},

		// --- gradeToExecute out of bounds ---
		{"Test 6 gradeToExecute=0 (invalid, too high)", "Broken Form C", false, 50, 0},
		{"Test 7 gradeToExecute=151 (invalid, too low)", "Broken Form D", false, 50, 151},
	};
	for (size_t i = 0; i < (sizeof(fTests) / sizeof(fTests[0])); i++)
	{
		std::cout << "----- " << fTests[i].testName << " -----" << std::endl;
		try
		{
			Form f(fTests[i].name, fTests[i].isSign, fTests[i].gradeToSign, fTests[i].gradeToExecute);
			std::cout << "\033[32mSuccess: " << f << "\033[0m" << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "\033[31m" << e.what() << "\033[0m" << std::endl;
		}
	}

	std::cout << std::endl << std::endl << "||||||||| SIGNING TESTS |||||||||" << std::endl << std::endl;
	{
		std::cout << "----- Bureaucrat well qualified (grade 3) signs form requiring grade 5 -----" << std::endl;
		std::string fname = "Robotomy Request";
		std::string bname = "Strong";
		Form f(fname, false, 5, 45);
		Bureaucrat strong(bname, 3);
		strong.signForm(f);
		std::cout << f << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "----- Bureaucrat under-qualified (grade 100) signs form requiring grade 5 -----" << std::endl;
		std::string fname = "Robotomy Request";
		std::string bname = "Weak";
		Form f(fname, false, 5, 45);
		Bureaucrat weak(bname, 100);
		weak.signForm(f);
		std::cout << f << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "----- Bureaucrat exactly at threshold (grade 5) signs form requiring grade 5 -----" << std::endl;
		std::string fname = "Robotomy Request";
		std::string bname = "Exact";
		Form f(fname, false, 5, 45);
		Bureaucrat exact(bname, 5);
		exact.signForm(f);
		std::cout << f << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "----- Signing an already-signed form again -----" << std::endl;
		std::string fname = "Robotomy Request";
		std::string bname = "Strong";
		Form f(fname, false, 5, 45);
		Bureaucrat strong(bname, 3);
		strong.signForm(f);
		std::cout << "First attempt: " << f << std::endl;
		strong.signForm(f);
		std::cout << "Second attempt: " << f << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "----- Copy assignment: isSign propagates, name/grades stay untouched -----" << std::endl;
		std::string fname1 = "Signed Original";
		std::string fname2 = "Untouched Copy";
		Form original(fname1, false, 5, 45);
		Form copy(fname2, false, 10, 20);
		std::string bname = "Signer";
		Bureaucrat b(bname, 3);
		b.signForm(original);
		std::cout << "Before assignment, copy: " << copy << std::endl;
		copy = original;
		std::cout << "After assignment,  copy: " << copy << std::endl;
		std::cout << "(name and grades must remain \"Untouched Copy\" / 10 / 20, only isSign changes)" << std::endl;
	}
	std::cout << std::endl << std::endl << "||||||||| DIRECT beSigned() + try/catch TESTS |||||||||" << std::endl << std::endl;
	{
		std::cout << "----- Direct call to beSigned(), bureaucrat qualified: exception must NOT be thrown -----" << std::endl;
		std::string fname = "Direct Test A";
		std::string bname = "Qualified";
		Form f(fname, false, 50, 100);
		Bureaucrat b(bname, 10);
		try
		{
			f.beSigned(b);
			std::cout << "\033[32mNo exception thrown, form is now: " << f << "\033[0m" << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "\033[31mUnexpected exception: " << e.what() << "\033[0m" << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "----- Direct call to beSigned(), bureaucrat under-qualified: exception MUST be caught here -----" << std::endl;
		std::string fname = "Direct Test B";
		std::string bname = "Unqualified";
		Form f(fname, false, 5, 45);
		Bureaucrat b(bname, 100);
		try
		{
			f.beSigned(b);
			std::cout << "\033[31mNo exception thrown, but one was expected!\033[0m" << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "\033[32mCaught in main, as expected: " << e.what() << "\033[0m" << std::endl;
			std::cout << "Form remains unsigned: " << f << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "----- Direct construction of an invalid Form: exception MUST be caught here -----" << std::endl;
		std::string fname = "Direct Test C";
		try
		{
			Form f(fname, false, 200, 45);
			std::cout << "\033[31mNo exception thrown, but one was expected!\033[0m" << std::endl;
			(void)f;
		}
		catch (const std::exception& e)
		{
			std::cout << "\033[32mCaught in main, as expected: " << e.what() << "\033[0m" << std::endl;
		}
	}
	return 0;
}