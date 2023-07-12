#include "../inc/Zombie.hpp"
#include <iostream>
#include <string>

int main(void)
{
	Zombie *test[4];
	std::string str[4] = {"one", "two", "three", ""};
	std::cout << std::endl;
	std::cout << "NEW ZOMBIE ===========" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "=== New zombie '" << str[i] << "' ===" << std::endl;
		test[i] = newZombie(str[i]);
		std::cout << "--> Announce()" << std::endl;
		test[i]->announce();
	}
	std::cout << "\n\t\033[90m+++ Delete instances should call destructors +++\033[0m\n"
			  << std::endl;
	for (int i = 0; i < 4; i++)
		delete test[i];
	std::cout << std::endl;
	std::cout << "RANDOM CHUMP =========" << std::endl;
	std::cout << "=== Use randomChump with 'one' ===" << std::endl;
	randomChump(str[0]);
	std::cout << "=== Use randomChump with no mame ===" << std::endl;
	randomChump("");
	return (0);
}
