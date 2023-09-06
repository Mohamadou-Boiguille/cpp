#include <iostream>
#include "../inc/Cat.hpp"

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
    if (_thoughts)
	{
        delete _thoughts;
		_thoughts = NULL;
	}
}

Cat::Cat() : Animal("Cat") {
    setSound("Meow meow");
    std::cout << "Cat constructor called" << std::endl;
}