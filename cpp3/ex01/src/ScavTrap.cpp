#include "../inc/ScavTrap.hpp"

    // ClapTrap();
    // ClapTrap(std::string pl_name);
    // ClapTrap(const ClapTrap&);
    // ClapTrap &operator=(const ClapTrap&);
    // ~ClapTrap();
ScavTrap::ScavTrap()
	: ClapTrap("John Doe"), gate_keeper(0)
{
    set_energy_pts(100);
    set_hit_pts(50);
    set_damage_pts(20);
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name), gate_keeper(0)
{
    set_energy_pts(100);
    set_hit_pts(50);
    set_damage_pts(20);
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    this->gate_keeper = other.gate_keeper;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& other)
{
    ClapTrap::operator=(other);
    this->gate_keeper = other.gate_keeper;
    return *this;
}

void ScavTrap::attack(const std::string &target)
{
    std::cout << "ScavTrap " << get_name() << " attacks " << target;
    set_gate_keeper(-1);
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

void ScavTrap::guardGate(void)
{
    std::cout << " enter in gate keeper mode :";
    std::cout << " YOU SHALL NOT PASS !!!";
    set_gate_keeper(5);
}

void ScavTrap::set_gate_keeper(unsigned int amount)
{
    this->gate_keeper += amount;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << get_name() << " quit the game." << std::endl;
}