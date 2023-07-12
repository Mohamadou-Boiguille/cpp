#include "../inc/Zombie.hpp"

Zombie::Zombie()
{
	std::cout << name << "'s constructor is called" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << "'s destructor is called" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
	init_name(name);
	std::cout << name << "'s constructor with argument is called " << std::endl;
}

void Zombie::init_name(std::string zombie_name)
{
	name = zombie_name;
}
