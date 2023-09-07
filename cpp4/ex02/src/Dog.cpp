#include "../inc/Dog.hpp"
#include <cstdlib>

Dog::Dog() : Animal("Dog") {
    setSound("Wof wof");
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    if (this != &other)
        Animal::operator=(other);
    std::cout << "Dog assignation operator called" << std::endl;
    return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
    if (_thoughts)
	{
        delete _thoughts;
		_thoughts = NULL;
	}
}

void Dog::getThought()
{
	unsigned int	index;

	if (_thoughts)
	{
		index = rand() % 100;
		std::cout << "The " << getType() << " ";
		std::cout << _thoughts->getString(index) << std::endl;
	}
	else
		std::cout << "The " << getType() << " has no brain (means error)" << std::endl;
}
