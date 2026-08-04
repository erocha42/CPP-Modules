#include "replace.hpp"

static void	reline(std::ofstream& outfile, std::string line, std::string to_find, std::string newStr)
{
	std::string result;
	size_t		found;
	size_t		pos = 0;

	while ((found = line.find(to_find, pos)) != std::string::npos)
	{
		result += line.substr(pos, found - pos);
		result += newStr;
		pos = found + to_find.length();
	}
	result += line.substr(pos);
	outfile << result << std::endl;
}

int	main(int ac, char **av)
{
	std::string	line;
	std::string	filename;

	if (ac != 4 || av[2][0] == '\0')
	{
		std::cout << "Args Error" << std::endl;
		return 1;
	}
	filename = av[1];
	std::ifstream	infile(av[1]);
	if (!infile)
	{
		std::cout << "Infile Error" << std::endl;
		return 1;
	}
	std::string		outfilename = filename.append(".replace");
	std::ofstream	outfile(outfilename.c_str());
	if (!outfile)
	{
		std::cout << "Outfile Error" << std::endl;
		return 1;
	}
	while (getline(infile, line))
	{
		if (line.find(av[2]) != std::string::npos)
			reline(outfile, line, av[2], av[3]);
		else
			outfile << line << std::endl;
	}
}
