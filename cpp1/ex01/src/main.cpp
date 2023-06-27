#include "../inc/Zombie.hpp"

int main()
{
    int x = 5;
    std::cout << "\n===== CREATE =====" << std::endl;
    Zombie *z_array = zombieHorde(x, "jojo");
    std::cout << "\n==== ANNOUNCE ====" << std::endl;
    for(int i = 0; i < x; i++)
        (z_array)[i].announce();
    std::cout << "\n===== DELETE =====" << std::endl;
    delete[] z_array;
    return 0;
}
