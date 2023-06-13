#pragma once
#ifndef CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	std::string name;
	unsigned int hit_pts;
	unsigned int energy_pts;
	unsigned int damage_pts;
    void log(std::string name, std::string target, unsigned int damage, int type);
    std::string get_name();
    unsigned int get_hit_pts();
    unsigned int get_energy_pts();
    unsigned int get_damage_pts();
    void set_hit_pts(unsigned int amount);
    void set_energy_pts(void);
    void set_damage_pts(unsigned int amount);

  public:
    ClapTrap(std::string pl_name);
    ~ClapTrap();
	void attack(const std::string &target);
	void takeDamage(unsigned int amout);
	void beRepaired(unsigned int amout);
};

#endif // !CLAPTRAP_HPP
