#include "../inc/ScavTrap.hpp"

int main(int argc, char **argv)
{
    (void)argv;
    std::cout << "\n=========ClapTrap============\n" << std::endl;
    ClapTrap clapTrap("Alice");
    clapTrap.beRepaired(5);
    for (int i = 0; i < 11; i++)
        clapTrap.attack("Bob");
    clapTrap.beRepaired(5);
    clapTrap.beRepaired(5);
    clapTrap.takeDamage(3);
    clapTrap.takeDamage(4);
    clapTrap.takeDamage(5);
    clapTrap.takeDamage(6);
    clapTrap.attack("Bob");
    clapTrap.beRepaired(5);
    std::cout << "\n=========ScavTrap============\n" << std::endl;
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

    return 0;
}
