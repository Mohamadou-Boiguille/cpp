#ifndef ANIMAL_HPP
# define ANIMAL_HPP
#include <iostream>
class Animal {
public:
    Animal ();
    Animal (std::string type);
    Animal (const Animal &);
    Animal &operator=(const Animal  &);
    ~Animal ();
    void makeSound() const;
    std::string getType() const;
protected:
    void setSound(const std::string &sound);
    std::string _type;
    std::string _sound;
};

#endif