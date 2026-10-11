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
}