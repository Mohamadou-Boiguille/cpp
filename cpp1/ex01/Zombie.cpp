#include "Zombie.h"

Zombie::~Zombie()
{
    std::cout << name << " has been deleted" << std::endl;
}

void Zombie::announce(void)
{
std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::init_name(std::string zombie_name)
{
    name = zombie_name;
}

Zombie::Zombie(std::string name)
{
    init_name(name);
}

Zombie::Zombie()
{

}
