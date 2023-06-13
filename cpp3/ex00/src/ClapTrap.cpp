#include "../inc/ClapTrap.hpp"
#include <iostream>

#define ATT 1
#define DMG 2
#define NO_NRG 3
#define DEAD 4

ClapTrap::ClapTrap(std::string pl_name)
	: name(pl_name), hit_pts(10), energy_pts(10), damage_pts(0)
{
	std::cout << name << " enter in the game." << std::endl;
};
ClapTrap::~ClapTrap()
{
	std::cout << name << " quit the game." << std::endl;
};
void ClapTrap::log(std::string name, std::string target, unsigned int damage,
		int type)
{
    std::cout << name << " |E " << get_energy_pts();
    std::cout << "|H " << get_hit_pts();
    std::cout << "|D " << get_damage_pts() << "|";
	if (type == ATT)
	{
		std::cout << " attacks " << target << ", causing ";
		std::cout << damage << " points of damage." << std::endl;
	}
	else if (type == NO_NRG)
		std::cout << " has no more energy," << target << " canceled." << std::endl;
	else if (type == DMG)
	{
		std::cout << " is taking " << damage << " points of damage. ";
		std::cout << "New hit points (" << get_hit_pts() << ")" << std::endl;
	}
	else if (type == DEAD)
		std::cout << " is dead." << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (!get_hit_pts())
		return (log(get_name(), "", 0, DEAD));
	if (!get_energy_pts())
		return (log(name, " attack", 0, NO_NRG));
	set_energy_pts();
	log(get_name(), target, get_damage_pts(), true);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!get_hit_pts())
		return (log(get_name(), "", 0, DEAD));
	log(get_name(), "", amount, DMG);
	if (get_hit_pts() < amount)
	{
		set_hit_pts(-get_hit_pts());
		std::cout << name << " died." << std::endl;
	}
	else
		set_hit_pts(-amount);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!get_hit_pts())
		return (log(get_name(), "", 0, DEAD));
	if (!get_energy_pts())
		return (log(name, " repairing", 0, NO_NRG));
	set_energy_pts();
	set_hit_pts(amount);
	std::cout << get_name() << " is repairing (+" << amount;
	std::cout << "). New hit points : " << get_hit_pts() << std::endl;
}

unsigned int ClapTrap::get_hit_pts()
{
	return (ClapTrap::hit_pts);
}
unsigned int ClapTrap::get_energy_pts()
{
	return (energy_pts);
}
unsigned int ClapTrap::get_damage_pts()
{
	return (damage_pts);
}
void ClapTrap::set_hit_pts(unsigned int amount)
{
	if (hit_pts)
		ClapTrap::hit_pts += amount;
}
void ClapTrap::set_energy_pts()
{
	if (hit_pts)
		ClapTrap::energy_pts -= 1;
}
void ClapTrap::set_damage_pts(unsigned int amount)
{
	if (hit_pts)
		ClapTrap::damage_pts += amount;
}
std::string ClapTrap::get_name()
{
	return (ClapTrap::name);
}
