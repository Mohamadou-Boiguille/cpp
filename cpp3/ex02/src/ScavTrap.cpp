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
	if (!get_hit_pts())
    {
        std::cout << "Hey " << get_name() << " is dead !" << std::endl;
		return ;
    }
	set_energy_pts(get_energy_pts() - 1);
    std::cout << get_name() << " |E " << get_energy_pts();
    std::cout << "|H " << get_hit_pts();
    std::cout << "|D " << get_damage_pts() << "|";
	if (!get_energy_pts())
    {
        std::cout <<  " is out of energy, attack IMPOSSIBLE";
        std::cout << std::endl;
		return;
    }
    std::cout << " strikes at " << target << " dealing a damaging blow of ";
    std::cout << get_damage_pts() << " points." << std::endl;
}
