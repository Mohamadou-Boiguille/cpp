#include <iostream>
#include "../inc/Cat.hpp"

Cat::Cat(const Cat &rhs) : Animal(rhs) {
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &rhs)
        Animal::operator=(rhs);
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat() : Animal("Cat") {
    setSound("Meow meow");
    std::cout << "Cat constructor called" << std::endl;
}