#include "../inc/Brain.hpp"
#include <sstream>
#include <string>

Brain::Brain()
{
    initStrings();
	std::cout << "Brain class created" << std::endl;
}

Brain::Brain(const Brain &other)
{
    index = other.index + 1;
    for (int i = 0; i < 100; i++) {
        ideas[i] = other.ideas[i];
    }
}

Brain &Brain::operator=(const Brain &other)
{
    if (this != &other)
    {
        index = other.index + 1;
        for (int i = 0; i < 100; i++) {
            ideas[i] = other.ideas[i];
        }
    }
    std::cout << "Brain copy constructor is called." << std::endl;
    return *this;
}

Brain::~Brain()
{
	std::cout << "Brain class deleted" << std::endl;
}

std::string Brain::getString(int index)
{
	if (index >= 100)
    {
        std::stringstream over;
        over << "has no toughts";
        return (over.str());
    }
	if (this->ideas[index].empty())
        return ("has an indescriptible thought");
	return (this->ideas[index]);
};

void Brain::initStrings()
{
	std::string stringArr[100] = {
		"is chasing its tail",
		"wants to go outside",
		"is napping",
		"is playing with a toy",
        "",
		"is watching birds",
		"is purring",
		"is grooming itself",
		"is hungry",
        "",
		"wants attention",
		"is exploring",
		"is stretching",
		"is climbing a tree",
        "",
		"is hiding under the furniture",
		"is kneading",
		"is ignoring you",
		"is staring at something",
        "",
		"is meowing loudly",
		"is taking a bath",
		"is batting at a string",
		"is hunting imaginary prey",
        "",
		"is rubbing against your leg",
		"is sleeping peacefully",
		"is curling up in a cozy spot",
		"is sharpening its claws",
        "",
		"is begging for treats",
		"is playing with a paper ball",
		"is curious about something",
		"is sitting in a sunbeam",
        "",
		"is pouncing on a shadow",
		"is chasing a laser pointer",
		"is licking its paws",
		"is stealing your seat",
        "",
		"is rolling on the floor",
		"is pawing at a closed door",
		"is knocking things off the table",
		"is stretching out its back",
        "",
		"is hiding in a box",
		"is staring out the window",
		"is twirling around",
		"is kneading a blanket",
        "",
		"is sitting on a bookshelf",
		"is batting at a feather toy",
		"is grooming another cat",
		"is playing with a mouse toy",
        "",
		"is jumping from furniture to furniture",
		"is chasing its own shadow",
		"is basking in the sun",
		"is sleeping on a pile of clothes",
        "",
		"is perched on a high surface",
		"is flicking its tail",
		"is wagging its tail",
		"wants to go for a walk",
        "",
		"is napping",
		"is playing fetch",
		"is barking at a squirrel",
		"is wagging its tongue",
        "",
		"is waiting for a treat",
		"is hungry",
		"wants attention",
		"is sniffing around",
        "",
		"is rolling in the grass",
		"is chasing its own tail",
		"is digging a hole",
		"is begging for food",
        "",
		"is playing with a ball",
		"is running in circles",
		"is jumping for joy",
		"is panting after exercise",
        "",
		"is wagging its whole body",
		"is carrying a toy",
		"is sitting on command",
		"is giving you a high-five",
        "",
		"is catching a frisbee",
		"is fetching a stick",
		"is drooling over food",
		"is burying a bone",
        "",
		"is chasing its reflection",
		"is jumping into water",
		"is learning a new trick",
		"is playing",
		"bite your hand"};
    for(int i = 0; i < 100; i++)
        this->ideas[i] = stringArr[i];
}
