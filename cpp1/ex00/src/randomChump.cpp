#include "../inc/Zombie.hpp"

void randomChump(std::string name)
{
    if (name.empty())
        name = "Jane Doe";
    Zombie jane_doe(name);
    jane_doe.announce();
}
