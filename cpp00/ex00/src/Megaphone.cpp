#include "../inc/Megaphone.hpp"

Megaphone::Megaphone()
{
}

bool Megaphone::printUpper(int argc, char **argv)
{
	bool emptyInput = true;

	for (int i = 1; i < argc; i++)
	{
		std::string input = argv[i];
		if (input.empty())
			continue ;
		emptyInput = false;
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
    if (emptyInput)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
		std::cout << std::endl;
	return (emptyInput);
}
