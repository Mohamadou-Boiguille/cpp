#pragma once
#ifndef CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	std::string name;
	unsigned int hit_pts;
	unsigned int energy_pts;
	unsigned int damage_pts;
	void log(std::string name, std::string target, unsigned int damage, int type);

  public:
	// coplien
	ClapTrap();
	ClapTrap(std::string pl_name);
	ClapTrap &operator=(const ClapTrap &other);
	ClapTrap(std::string pl_name, std::string type);
	~ClapTrap();
	// methods
	virtual void attack(const std::string &target);
	virtual void takeDamage(unsigned int amout);
	virtual void beRepaired(unsigned int amout);
	// setters and getters
	void set_hit_pts(unsigned int amount);
	void set_energy_pts(unsigned int amount);
	void set_damage_pts(unsigned int amount);
	std::string &get_name();
	unsigned int get_hit_pts() const;
	unsigned int get_energy_pts() const;
	unsigned int get_damage_pts() const;
};

#endif // !CLAPTRAP_HPP
