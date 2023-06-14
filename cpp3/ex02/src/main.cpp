#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"

int main(int argc, char **argv)
{
    (void)argv;
    std::cout << "\n=========FragTrap============\n" << std::endl;
    FragTrap second("Bonnie");
    for (int i = 0; i < 13; i++)
        second.attack("Clyde");
    if (argc == 2)
    {
        for (int i = 0; i < 90; i++)
            second.attack("Clyde");
    }
    second.highFivesGuys();
    second.beRepaired(5);
    second.beRepaired(5);
    for (int i = 0; i < 13; i++)
        second.takeDamage(10);
    second.attack("Clyde");
    second.beRepaired(5);

    return 0;
}
