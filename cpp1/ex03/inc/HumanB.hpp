#pragma once
#ifndef HUMANB_HPP

# include "../inc/Weapon.hpp"
# include <iostream>

class HumanB
{
	std::string name;
	Weapon *weapon;

  public:
	HumanB(const std::string &name);
	void attack();
	void setWeapon(Weapon &in_weapon);
};

#endif // !HUMANB_HPP
