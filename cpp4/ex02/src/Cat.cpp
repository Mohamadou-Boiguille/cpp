#include "../inc/Cat.hpp"
#include <iostream>


Cat::Cat()
	: Animal("Cat"), toughts(new Brain())
{
	setSound("Meow");
}

Cat::Cat(const Cat &copy) : Animal(copy), toughts(new Brain(*(copy.toughts)))
{
}

Cat &Cat::operator=(const Cat &copy)
{
    if(this != &copy)
    {
        Animal::operator=(copy);
        index = copy.index + 1;
        toughts = new Brain();
    }
    return (*this);
}

void Cat::getThought()
{
	std::cout << "The Cat nb " << getIndex();
	std::cout << " " << toughts->getString(getIndex()) << std::endl;
}

Cat::~Cat()
{
	if (toughts)
    {
		delete toughts;
    }
}
