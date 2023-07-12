#include "../inc/Megaphone.hpp"

Megaphone::Megaphone()
{
}

void Megaphone::printUpper(int argc, char **argv)
{
	bool emptyInput = true;

	for (int i = 1; i < argc; i++)
	{
		std::string input = argv[i];
		std::string::iterator it = input.begin();
		while (isspace(*it))
			it++;
		if (it != input.end())
			emptyInput = false;
		else
			continue;
		while (it != input.end())
			putchar(toupper(*(it++)));
		if (*(it - 1) != ' ' && argv[i + 1])
			std::cout << " ";
	}
	if (emptyInput)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
}
