#pragma once
#ifndef SCAVTRAP_HPP

#include "../inc/ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
  public:
	// coplien
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);
	~ScavTrap();
	// methods
	virtual void attack(const std::string &target);
	virtual void takeDamage(unsigned int amout);
	virtual void beRepaired(unsigned int amout);
	void guardGate();
};
#endif
