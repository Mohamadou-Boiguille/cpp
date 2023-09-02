#include "../inc/ScavTrap.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	{
		std::cout << "\n=========first============\n"
				  << std::endl;
		ClapTrap first("Alice");
		first.beRepaired(5);
		for (int i = 0; i < 3; i++)
			first.attack("Bob");
		first.beRepaired(5);
		first.beRepaired(5);
		first.takeDamage(3);
		first.takeDamage(4);
		first.takeDamage(5);
		first.takeDamage(6);
		first.attack("Bob");
		first.beRepaired(5);
	}
	{
		std::cout << "\n=========ScavTrap============\n"
				  << std::endl;
		ScavTrap second("Bonnie");
		for (int i = 0; i < 2; i++)
			second.attack("Clyde");
		if (argc == 2)
		{
			for (int i = 0; i < 90; i++)
				second.attack("Clyde");
		}
		second.beRepaired(5);
		second.beRepaired(5);
		for (int i = 0; i < 3; i++)
			second.takeDamage(10);
		second.attack("Clyde");
		second.beRepaired(5);
		second.guardGate();
	}
	std::cout << "\n=========ScavTrap ptr============\n"
			  << std::endl;
	ScavTrap *third = new ScavTrap("Bonnie");
	for (int i = 0; i < 2; i++)
		third->attack("Clyde");
	if (argc == 2)
	{
		for (int i = 0; i < 90; i++)
			third->attack("Clyde");
	}
	third->beRepaired(5);
	third->beRepaired(5);
	for (int i = 0; i < 3; i++)
		third->takeDamage(10);
	third->attack("Clyde");
	third->beRepaired(5);
	third->guardGate();
	delete third;
	return 0;
}
