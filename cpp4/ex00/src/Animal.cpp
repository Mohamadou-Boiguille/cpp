#include "../inc/Animal.hpp"

Animal::Animal() : _type("Unknown animal") , _sound("Unknown sound"){
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &other) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

Animal &Animal::operator=(const Animal &other) {
    std::cout << "Animal assignation operator called" << std::endl;
    if (this != &other)
        this->_type = other._type;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
    return this->_type;
}

void Animal::makeSound() const{
    std::cout << getType() << ": " << _sound << std::endl;
}

std::ostream &operator<<(std::ostream &o, const Animal &i) {
    o << i.getType();
    return o;
}

void Animal::setSound(const std::string &sound) {
    _sound = sound;
}