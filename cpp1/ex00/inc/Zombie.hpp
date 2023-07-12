#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include <string>

class Zombie
{
  public:
	Zombie();
	~Zombie();
	Zombie(std::string name);
	void announce(void);

  private:
	std::string name;
	void init_name(std::string zombie_name);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif // !ZOMBIE_H
