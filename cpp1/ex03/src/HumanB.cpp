#include "../inc/HumanB.hpp"

HumanB::HumanB(const std::string &name)
	: name(name), weapon(NULL){};
void HumanB::attack()
{
    if (this->weapon && !this->weapon->getType().empty())
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " attacks with their NOTHING. " << name << " is unarmed !!!" << std::endl;
}
void HumanB::setWeapon(Weapon &in_weapon)
{
	this->weapon = &in_weapon;
}
