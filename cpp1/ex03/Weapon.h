#pragma once
#include <iostream>

class Weapon
{
public:
    Weapon();

    const std::string& getType();

    void setType(std::string type);

private:
    std::string type;

};
