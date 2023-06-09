#include "../inc/Zombie.hpp"

int	main(void)
{
    Zombie *test[3];
    std::cout << "\n   NEW ZOMBIE =======================\n" << std::endl;
    std::cout << "\n\t\033[90m=== Create a new zombie called 'Zomb_one' ===\033[0m" << std::endl;
    test[0] = newZombie("Zomb_one");
    std::cout << "\t\033[90m Announce 'Zomb_one'\033[0m" << std::endl;
    test[0]->announce();
    std::cout << "\t\033[90m=== Create a new zombie called 'Zomb_two' ===\033[0m" << std::endl;
    test[1] = newZombie("Zomb_two");
    std::cout << "\t\033[90m Announce 'Zomb_two'\033[0m" << std::endl;
    test[1]->announce();
    std::cout << "\t\033[90m=== Create a new zombie whithout name ===\033[0m" << std::endl;
    test[2] = newZombie("");
    std::cout << "\t\033[90m Announce anonymous\033[0m" << std::endl;
    test[2]->announce();
    std::cout << "\n\t\033[90m+++ Delete instances should call destructors +++\033[0m\n" << std::endl;
    delete test[0];
    delete test[1];
    delete test[2];
    std::cout << "\n   RANDOM CHUMP =====================\n" << std::endl;
    std::cout << "\t\033[90m=== Use randomChump with 'jojo' ===\033[0m" << std::endl;
    randomChump("jojo");
    std::cout << "\t\033[90m=== Use randomChump with empty string ===\033[0m\n" << std::endl;
    randomChump("");
    return (0);
}
