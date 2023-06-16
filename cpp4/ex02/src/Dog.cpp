#include "../inc/Dog.hpp"
#include <iostream>

Dog::Dog()
	: Animal("Dog"), toughts(new Brain())
{
	setSound("Wof Wof");
}

Dog::Dog(const Dog &copy) : Animal(copy), toughts(new Brain(*(copy.toughts)))
{
}

Dog &Dog::operator=(const Dog &copy)
{
    if(this != &copy)
    {
        Animal::operator=(copy);
        index = copy.index + 1;
        toughts = new Brain();
    }
    return (*this);
}

void Dog::getThought()
{
	std::cout << "The Dog nb " << getIndex();
	std::cout << " " << toughts->getString(getIndex()) << std::endl;
}

Dog::~Dog()
{
	if (toughts)
    {
		delete toughts;
    }
}
