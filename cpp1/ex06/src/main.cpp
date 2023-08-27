#include "../inc/Harl.hpp"
#include <ctime>
#include <string>

int main(int argc, char **argv)
{
	Harl Mr_Harl;
	if (argc == 1)
	{
		std::srand(std::time(0));
		int random_nb = std::rand() % 3;
		std::string level = Mr_Harl.get_type(random_nb);
		std::cout << "Random filter level => " << level << std::endl;
		Mr_Harl.filter(level);
	}
	else if (argc != 2)
	{
		std::cout << "Harl need one parameter" << std::endl;
		return (0);
	}
	else
		Mr_Harl.filter((std::string)argv[1]);
	return 0;
}
