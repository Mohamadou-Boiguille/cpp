#include "../inc/ScavTrap.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	std::cout << "\n=========first============\n"
			  << std::endl;
	ClapTrap first("Alice");
	first.beRepaired(5);
	for (int i = 0; i < 11; i++)
		first.attack("Bob");
	first.beRepaired(5);
	first.beRepaired(5);
	first.takeDamage(3);
	first.takeDamage(4);
	first.takeDamage(5);
	first.takeDamage(6);
	first.attack("Bob");
	first.beRepaired(5);
	std::cout << "\n=========ScavTrap============\n"
			  << std::endl;
	ScavTrap second("Bonnie");
	for (int i = 0; i < 13; i++)
		second.attack("Clyde");
	if (argc == 2)
	{
		for (int i = 0; i < 90; i++)
			second.attack("Clyde");
	}
	second.beRepaired(5);
	second.beRepaired(5);
	for (int i = 0; i < 13; i++)
		second.takeDamage(10);
	second.attack("Clyde");
	second.beRepaired(5);
	second.guardGate();

	return 0;
}
