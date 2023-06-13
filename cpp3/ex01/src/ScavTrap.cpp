#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
    set_energy_pts(100);
    set_hit_pts(50);
    set_damage_pts(20);
}

void ScavTrap::attack(const std::string &target)
{
    std::cout << " |E " << get_energy_pts();
    std::cout << "|H " << get_hit_pts();
    std::cout << "|D " << get_damage_pts() << "|\t" << get_name();
	if (!get_hit_pts())
    {
        std::cout << " Hey I'm is dead !" << std::endl;
		return ;
    }
	if (!get_energy_pts())
    {
        std::cout <<  " is out of energy, attack IMPOSSIBLE";
        std::cout << std::endl;
		return;
    }
	set_energy_pts(get_energy_pts() - 1);
    std::cout << " attacks " << target << ", causing ";
    std::cout << get_damage_pts() << " points of damage." << std::endl;
}
