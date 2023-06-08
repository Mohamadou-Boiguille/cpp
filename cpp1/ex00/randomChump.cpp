#include "Zombie.h"

void randomChump(std::string name)
{
    Zombie rc_zombie(name);
    rc_zombie.announce();
}
