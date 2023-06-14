#include "../inc/Dog.hpp"
#include <iostream>

Dog::Dog() : Animal(typeid(*this).name() + 1) 
{
    set_sound("Wof Wof");
}

Dog::~Dog() {}
