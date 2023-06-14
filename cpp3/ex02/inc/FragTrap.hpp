#pragma once
#ifndef FRAGTRAP_HPP

# include "../inc/ClapTrap.hpp"

class FragTrap : public ClapTrap
{
  public:
    FragTrap(std::string name);
    ~FragTrap();
    void highFivesGuys(void);
};

#endif //FRAGTRAP_HPP
