# include "../inc/Weapon.hpp"
#include <iostream>

Weapon::Weapon(const std::string& w_type): type(w_type){};

void Weapon::setType(std::string type)
{
    if (type.empty())
        type = "uknown but powerful (I guess) weapon";
    Weapon::type = type;
}

const std::string Weapon::getType()
{
    return (type);
}
