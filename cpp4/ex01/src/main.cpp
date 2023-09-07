#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <algorithm>

static void populateArray(Animal *dogsAnCatsArray[]);
static void castAndLog(Animal *dogsAnCatsArray[], int index);
static void deleteArray(Animal *dogsAnCatsArray[]);

int main()
{
	Animal *dogsAnCatsArray[10];
	int index;
	std::string answer;

	populateArray(dogsAnCatsArray);
	while (true)
	{
		std::cout << std::endl;
		std::cout << "===> Ask for any animal thought ";
		std::cout << "(give his index 0 to 9 - q to quit) : ";
		std::cin >> answer;
		if (answer == "" || answer.empty() || answer.at(0) == '\n' || answer.at(0) == ' ')
			continue;
		if (std::cin.eof() || answer.at(0) == 'q' || answer.at(0) == 'Q')
			break;
		std::istringstream iss(answer);
		if (!(iss >> index))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		castAndLog(dogsAnCatsArray, index);
	}
	deleteArray(dogsAnCatsArray);
	return (0);
}

static void populateArray(Animal *dogsAnCatsArray[])
{
	std::cout << "===== create a dogs and cats array =====" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "  ----" << i << std::endl;
		if (i % 2)
			dogsAnCatsArray[i] = new Dog();
		else
			dogsAnCatsArray[i] = new Cat();
	}
}

static void deleteArray(Animal *dogsAnCatsArray[])
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << "  ----" << i << std::endl;
		delete dogsAnCatsArray[i];
	}
}

static void castAndLog(Animal *dogsAnCatsArray[], int index)
{
	Animal *animal;

	if (index > 9 || index < 0)
		std::cout << "Index out of range / handle new index" << std::endl;
	if (index < 0)
		index = -index;
	if (index > 10)
		index = index % 10;
	std::cout << "===== At place " << index << " =====" << std::endl;
	animal = dogsAnCatsArray[index];
	animal->makeSound();
	animal->getThought();
}