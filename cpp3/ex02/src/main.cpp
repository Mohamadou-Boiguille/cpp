#include "../inc/FragTrap.hpp"
#include "../inc/ScavTrap.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	std::cout << "\n=========FragTrap============\n"
			  << std::endl;
	FragTrap testClass("Bonnie");
	for (int i = 0; i < 13; i++)
		testClass.attack("Clyde");
	if (argc == 2)
	{
		for (int i = 0; i < 90; i++)
			testClass.attack("Clyde");
	}
	testClass.highFivesGuys();
	testClass.beRepaired(5);
	testClass.beRepaired(5);
	for (int i = 0; i < 13; i++)
		testClass.takeDamage(10);
	std::cout << "--- try attack but dead ---" << std::endl;
	testClass.attack("Clyde");
	std::cout << "--- try repair but dead ---" << std::endl;
	testClass.beRepaired(5);

	return 0;
}
