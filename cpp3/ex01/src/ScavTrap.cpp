#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
    ScavTrap::hit_pts = 100;
	ScavTrap::energy_pts = 50;
	ScavTrap::damage_pts = 20;
}
