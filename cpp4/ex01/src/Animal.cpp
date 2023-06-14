#include "../inc/Animal.hpp"

Animal::Animal() {
    set_type("Unknown Animal");
    set_sound("Indescriptible sound");
    std::cout << "Animal's constructor applied" << std::endl;
}

Animal::Animal(const std::string new_type) : type(new_type){
    std::cout << getType() << " constructor is called." << std::endl;
}

Animal::~Animal()
{
    std::cout << getType() << "'s destructor applied" << std::endl;
}

void Animal::set_type(std::string new_type)
{
    this->type = new_type;
}

std::string Animal::getType() const
{
    return this->type;
}

std::string Animal::getSound() const
{
    return Animal::sound;
}

void Animal::set_sound(std::string new_sound)
{
    this->sound = new_sound;
}

void Animal::makeSound(void) const
{
    std::cout << getSound() << std::endl;
}
