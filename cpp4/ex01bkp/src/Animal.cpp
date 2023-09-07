#include "../inc/Animal.hpp"

int Animal::nextIndex = 0;

Animal::Animal() {
    index = nextIndex++;
    setType("Unknown Animal");
    setSound("Indescriptible sound");
    std::cout << "Animal's constructor applied" << std::endl;
}

Animal::Animal(const std::string newType) : type(newType){
    std::cout << getType() << " constructor is called." << std::endl;
}

Animal::Animal(const Animal& other) {
    index = ++nextIndex;
    type = other.type;
    sound = other.sound;
    std::cout << getType() << " nb " << getIndex();
    std::cout << " copy constructor is called." << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        type = other.type;
        sound = other.sound;
    }
    this->index = other.nextIndex++;
    std::cout << getType() << " assignment operator is called." << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << "The destructor of the " << getType() << " number ";
    std::cout << getIndex() << " is called" << std::endl;
}

void Animal::setType(std::string newType)
{
    this->type = newType;
}

std::string Animal::getType() const
{
    return this->type;
}

std::string Animal::getSound() const
{
    return Animal::sound;
}

void Animal::setSound(std::string newSound)
{
    this->sound = newSound;
}

void Animal::makeSound(void) const
{
    std::cout << getSound() << std::endl;
}

int Animal::getIndex()
{
    return this->index;
}

