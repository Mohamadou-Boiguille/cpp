#include "../inc/Dog.hpp"

Dog::Dog() : Animal("Dog") {
    setSound("Wof wof");
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &rhs) : Animal(rhs) {
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs) {
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &rhs)
        Animal::operator=(rhs);
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}