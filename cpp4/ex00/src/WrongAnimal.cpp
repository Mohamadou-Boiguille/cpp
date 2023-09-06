#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Wrong animal") , _sound("Wrong sound"){
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    std::cout << "WrongAnimal assignation operator called" << std::endl;
    if (this != &other)
        this->_type = other._type;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->_type;
}

void WrongAnimal::makeSound() const{
    std::cout << getType() << ": " << _sound << std::endl;
}

std::ostream &operator<<(std::ostream &o, const WrongAnimal &i) {
    o << i.getType();
    return o;
}

void WrongAnimal::setSound(const std::string &sound) {
    _sound = sound;
}