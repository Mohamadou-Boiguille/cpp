#include "../inc/HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon){}

void HumanA::attack()
{
    if (!this->weapon.getType().empty())
        std::cout << name << " attacks with their " << weapon.getType() << std::endl;
    else
        std::cout << name << " attacks with their ... Nada" << std::endl;
}
