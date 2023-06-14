#pragma once
#ifndef ANIMAL_HPP
# define ANIMAL_HPP
#include <iostream>
#include <string>
#include <typeinfo>

class Animal {
public:
    Animal();
    Animal(const std::string new_type);
    Animal(const Animal &);
    Animal &operator=(const Animal &);
    virtual ~Animal();

    void makeSound(void) const;
    void set_type(std::string new_type);
    void set_sound(std::string new_sound);

    std::string getType() const;
    std::string getSound() const;

protected:
    std::string type;
    std::string sound;
};

#endif // !ANIMAL_HPP
