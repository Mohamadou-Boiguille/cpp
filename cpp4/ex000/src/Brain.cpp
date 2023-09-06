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
		index = index % 100;
	if (this->ideas[index].empty())
        return ("has an indescriptible thought");
	return (this->ideas[index]);
};

void Brain::initStrings()
{
	std::string stringArr[100] = {
		"think of chasing its tail",
		"wants to go outside",
		"think of napping",
		"think of playing with a toy",
        "think of doing nothing",
		"think of watching birds",
		"think of purring",
		"think of grooming itself",
		"think of hungry",
        "think of doing nothing",
		"wants attention",
		"think of exploring",
		"think of stretching",
		"think of climbing a tree",
        "think of doing nothing",
		"think of hiding under the furniture",
		"think of kneading",
		"think of ignoring you",
		"think of staring at something",
        "think of doing nothing",
		"think of meowing loudly",
		"think of taking a bath",
		"think of batting at a string",
		"think of hunting imaginary prey",
        "think of doing nothing",
		"think of rubbing against your leg",
		"think of sleeping peacefully",
		"think of curling up in a cozy spot",
		"think of sharpening its claws",
        "think of doing nothing",
		"think of begging for treats",
		"think of playing with a paper ball",
		"think of curious about something",
		"think of sitting in a sunbeam",
        "think of doing nothing",
		"think of pouncing on a shadow",
		"think of chasing a laser pointer",
		"think of licking its paws",
		"think of stealing your seat",
        "think of doing nothing",
		"think of rolling on the floor",
		"think of pawing at a closed door",
		"think of knocking things off the table",
		"think of stretching out its back",
        "think of doing nothing",
		"think of hiding in a box",
		"think of staring out the window",
		"think of twirling around",
		"think of kneading a blanket",
        "think of doing nothing",
		"think of sitting on a bookshelf",
		"think of batting at a feather toy",
		"think of grooming another cat",
		"think of playing with a mouse toy",
        "think of doing nothing",
		"think of jumping from furniture to furniture",
		"think of chasing its own shadow",
		"think of basking in the sun",
		"think of sleeping on a pile of clothes",
        "",
		"think of perched on a high surface",
		"think of flicking its tail",
		"think of wagging its tail",
		"wants to go for a walk",
        "think of doing nothing",
		"think of napping",
		"think of playing fetch",
		"think of barking at a squirrel",
		"think of wagging its tongue",
        "",
		"think of waiting for a treat",
		"think of hungry",
		"wants attention",
		"think of sniffing around",
        "think of doing nothing",
		"think of rolling in the grass",
		"think of chasing its own tail",
		"think of digging a hole",
		"think of begging for food",
        "think of doing nothing",
		"think of playing with a ball",
		"think of running in circles",
		"think of jumping for joy",
		"think of panting after exercise",
        "think of doing nothing",
		"think of wagging its whole body",
		"think of carrying a toy",
		"think of sitting on command",
		"think of giving you a high-five",
        "think of doing nothing",
		"think of catching a frisbee",
		"think of fetching a stick",
		"think of drooling over food",
		"think of burying a bone",
        "think of doing nothing",
		"think of chasing its reflection",
		"think of jumping into water",
		"think of learning a new trick",
		"think of playing",
		"bite your hand"};
    for(int i = 0; i < 100; i++)
        this->ideas[i] = stringArr[i];
}
