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
	std::cout << "ScavTrap: ";
	ClapTrap::attack(target);
}

void ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "ScavTrap: ";
	ClapTrap::takeDamage(amount);
}

void ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << "ScavTrap: ";
	ClapTrap::beRepaired(amount);
}
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap: " << get_name() << " enter in Guard Gate mode." << std::endl;
}

// coplien
ScavTrap::ScavTrap()
	: ClapTrap("John Doe")
{
	set_energy_pts(100);
	set_hit_pts(50);
	set_damage_pts(20);
}

ScavTrap::ScavTrap(const ScavTrap &other)
	: ClapTrap(other)
{
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap()
{
}
