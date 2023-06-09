#include <cstdio>
#include <iostream>
#include <string>

class Megaphone
{
  public:
	Megaphone();

	Megaphone(std::string input);

	bool print_str_to_lower(int argc, char **argv);
};

Megaphone::Megaphone()
{
}

bool Megaphone::print_str_to_lower(int argc, char **argv)
{
	bool is_all_empty = false;

	for (size_t i = 1; i < static_cast<size_t>(argc); i++)
	{
		std::string input = argv[i];
		if (input.empty())
			continue ;
		is_all_empty = true;
		std::string::iterator it = input.begin();
		while (isspace(*it))
			it++;
		while (it != input.end())
		{
			putchar(toupper(*it));
			it++;
		}
		if (*(it - 1) != ' ' && argv[i + 1])
			std::cout << " ";
	}
	if (is_all_empty)
		std::cout << std::endl;
	return (is_all_empty);
}

int	main(int argc, char *argv[])
{
	Megaphone	str;

	if (argc == 1 || !str.print_str_to_lower(argc, argv))
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
