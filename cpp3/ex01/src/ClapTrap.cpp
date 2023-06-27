#include "../inc/ClapTrap.hpp"
#include <iostream>

#define ATT 1
#define DMG 2
#define NO_NRG 3
#define DEAD 4
# define REPAIR 5

ClapTrap::ClapTrap() : name("John Doe")
{
	std::cout << name << " enter the game." << std::endl;
}

ClapTrap::ClapTrap(std::string pl_name)
	: name(pl_name), hit_pts(10), energy_pts(10), damage_pts(0)
{
	std::cout << name << " enter in the game." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    this->name = other.name;
    this->hit_pts = other.hit_pts;
    this->energy_pts = other.energy_pts;
    this->damage_pts = other.damage_pts;
}

ClapTrap &ClapTrap::operator=(const ClapTrap&other)
{
    if (this != &other)
        this->name = other.name;
    return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << name << " quit the game." << std::endl;
}

void ClapTrap::log(std::string name, std::string target, unsigned int damage,
		int type)
{
    std::cout << name << " |E " << get_energy_pts();
    std::cout << "|H " << get_hit_pts();
    std::cout << "|D " << get_damage_pts() << "|";
    if (type == ATT)
	{
		std::cout << " attacks " << target << ", causing ";
		std::cout << damage << " points of damage. (-1 Energy)" << std::endl;
	}
    else if (type == NO_NRG)
		std::cout << " has no more energy," << target << " canceled." << std::endl;
    else if (type == DMG)
	{
		std::cout << " is taking " << damage << " points of damage. ";
		std::cout << get_hit_pts() << " hit points left" << std::endl;
	}
    else if (type == DEAD)
		std::cout << " is dead and couldn't play." << std::endl;
    else if (type == REPAIR)
    {
        set_energy_pts(-1);
        std::cout << " is repairing. (" << get_hit_pts() << ") +"<< damage;
        std::cout  << " hit points.";
        std::cout << " (-1 Energy)"<< std::endl;
        set_hit_pts(damage);
    }
}

void ClapTrap::attack(const std::string &target)
{
	if (!get_hit_pts())
		return (log(get_name(), "", 0, DEAD));
	if (!get_energy_pts())
		return (log(name, " attack", 0, NO_NRG));
	set_energy_pts(-1);
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
    log(get_name(), "is repairing", amount, REPAIR);
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
void ClapTrap::set_energy_pts(unsigned int amount)
{
    if (amount > 0)
        this->energy_pts = amount;
    else if (hit_pts)
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
