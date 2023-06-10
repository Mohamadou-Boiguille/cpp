#pragma once
#ifndef WEAPON_H

#include <iostream>
#include <string>

class Weapon
{
public:
    Weapon(const std::string& w_type);

    const std::string getType();

    void setType(std::string type);

private:
    std::string type;
};

#endif // !WEAPON_H
