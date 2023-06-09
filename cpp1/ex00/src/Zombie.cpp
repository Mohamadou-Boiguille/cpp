#include "../inc/Zombie.hpp"

Zombie::Zombie()
{
    std::cout << name << "'s constructor has worked" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << "'s destructor has worked" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
    init_name(name);
    std::cout << name << "'s constructor has worked" << std::endl;
}

void Zombie::init_name(std::string zombie_name)
{
    name = zombie_name;
}
