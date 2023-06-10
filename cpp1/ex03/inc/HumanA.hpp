#pragma once
#ifndef HUMANA_HPP

# include "../inc/Weapon.hpp"
# include <iostream>

class HumanA
{
	std::string name;
	Weapon &weapon;

  public:
	HumanA(const std::string &name, Weapon &weapon);
	void attack();
};

#endif // !HUMANA_HPP
