#pragma once
#ifndef SCAVTRAP_HPP

#include "../inc/ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
	unsigned int gate_keeper;

  public:
	ScavTrap();
	ScavTrap(std::string name);
	void attack(const std::string &target);
	void guardGate(void);
	void set_gate_keeper(unsigned int amount);
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);
	~ScavTrap();
};
#endif
