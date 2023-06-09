#include "../inc/Zombie.hpp"

Zombie *newZombie(std::string name)
{
    if (name.empty())
        name = "John Doe";
    return (new Zombie(name));
}
