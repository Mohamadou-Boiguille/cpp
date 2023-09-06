#include "../inc/Animal.hpp"
#include <cstdlib>

Animal::Animal() : _type("Unknown animal"), _sound("Unknown sound")
{
	std::cout << "Animal constructor called" << std::endl;
	_thoughts = new Brain();
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal constructor called" << std::endl;
	_thoughts = new Brain();
}

Animal::Animal(const Animal &other) : _type(other._type), _sound(other._sound)
{
	std::cout << "Animal copy constructor called" << std::endl;
	_thoughts = new Brain(*(other._thoughts));
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &other)
	{
		_type = other._type;
		_sound = other._sound;
		delete _thoughts;
		_thoughts = new Brain();
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
    if (_thoughts)
	{
        delete _thoughts;
		_thoughts = NULL;
	}
}

std::string Animal::getType() const
{
	return (this->_type);
}

void Animal::makeSound() const
{
	std::cout << getType() << ": " << _sound << std::endl;
}

void Animal::setSound(const std::string &sound)
{
	_sound = sound;
}

void Animal::getThought()
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
