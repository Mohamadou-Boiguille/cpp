#pragma once
#ifndef SCAVTRAP_HPP

# include "../inc/ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
  public:
    ScavTrap(std::string name);
    void attack(const std::string &target);
};

#endif
