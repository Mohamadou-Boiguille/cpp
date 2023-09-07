#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

int main()
{
	Animal *dogsAnCatsArray[3];

	dogsAnCatsArray[0] = new Dog();
	dogsAnCatsArray[1] = new Cat();
	// dogsAnCatsArray[2] = new Animal();
	delete dogsAnCatsArray[0];
	delete dogsAnCatsArray[1];
	return (0);
}
