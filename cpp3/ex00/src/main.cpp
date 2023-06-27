#include "../inc/ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap("Alice");
    clapTrap.attack("Bob");
    clapTrap.beRepaired(5);
    for (int i = 0; i < 13; i++)
        clapTrap.attack("Bob");
    clapTrap.beRepaired(5);
    clapTrap.beRepaired(5);
    clapTrap.takeDamage(3);
    clapTrap.takeDamage(4);
    clapTrap.takeDamage(5);
    clapTrap.takeDamage(6);
    clapTrap.attack("Bob");
    clapTrap.beRepaired(5);

    return 0;
}
