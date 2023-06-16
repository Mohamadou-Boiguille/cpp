#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include <iostream>
#include <sstream>
#include <string>

static void	populateArray(Animal *dogsAnCatsArray[]);
void		castAndLog(Animal *dogsAnCatsArray[], int index);

int	main(int argc, char **argv)
{
	Animal	*dogsAnCatsArray[100];
	int		index;

    // Animal animal;
	std::string answer = " ";
	(void)argv;
	populateArray(dogsAnCatsArray);
	while (!answer.empty() && argc != 2)
	{
		std::cout << "===> Ask for any animal thought ";
		std::cout << "(give his index 0 to 99 - e to exit) : ";
		std::cin >> answer;
		if (std::cin.eof())
			break ;
		if (answer.at(0) == 'e' || answer.at(0) == 'E')
			break ;
		std::istringstream iss(answer);
		if (!(iss >> index))
			continue ;
		castAndLog(dogsAnCatsArray, index);
	}
	for (int i = 0; i < 100; i++)
		delete dogsAnCatsArray[i];
	return (0);
}

static void	populateArray(Animal *dogsAnCatsArray[])
{
    Dog *baseDog;
    Cat *baseCat;
	std::cout << "===== create a dogs and cats array =====" << std::endl;
	for (int i = 0; i < 100; i++)
	{
        if (i == 0 || i == 50)
        {
            if (i == 0)
                dogsAnCatsArray[0] = baseDog = new Dog;
            if (i == 50)
                dogsAnCatsArray[50] = baseCat = new Cat;
            continue;
        }
        else if (i > 0 && i < 50)
            dogsAnCatsArray[i] = new Dog(*baseDog);
        else if (i > 50)
            dogsAnCatsArray[i] = new Cat(*baseCat);
	}
}

void	castAndLog(Animal *dogsAnCatsArray[], int index)
{
	Dog	*dog;
	Cat	*cat;

	if (index >= 0 && index < 50)
	{
		dog = dynamic_cast<Dog *>(dogsAnCatsArray[index]);
		dog->makeSound();
		dog->getThought();
	}
	else if (index >= 50 && index < 100)
	{
		cat = dynamic_cast<Cat *>(dogsAnCatsArray[index]);
		cat->makeSound();
		cat->getThought();
	}
	else
		std::cout << "out of the range" << std::endl;
}
