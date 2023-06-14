#include "../inc/Cat.hpp"

Cat::Cat() : Animal(typeid(*this).name() + 1) 
{
    set_sound("Meow");
}

Cat::~Cat() {}
