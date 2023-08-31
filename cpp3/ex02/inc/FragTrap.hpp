#pragma once
#ifndef FRAGTRAP_HPP

#include "../inc/ClapTrap.hpp"

class FragTrap : public ClapTrap
{
  public:
	// coplien
	FragTrap();
	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &other);
	FragTrap(std::string name);
	~FragTrap();
	// methods
	virtual void attack(const std::string &target);
	virtual void takeDamage(unsigned int amout);
	virtual void beRepaired(unsigned int amout);
	void highFivesGuys(void);
};

#endif // FRAGTRAP_HPP
