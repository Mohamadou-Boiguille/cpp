#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal {
public:
    Animal ();
    Animal (std::string type);
    Animal (const Animal &);
    Animal &operator=(const Animal  &);
    virtual ~Animal ();
    void makeSound() const;
    std::string getType() const;
    virtual void getThought() = 0;
protected:
    void setSound(const std::string &sound);
    std::string _type;
    std::string _sound;
	Brain *_thoughts;
};

#endif