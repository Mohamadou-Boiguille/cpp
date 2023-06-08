#pragma once
#ifndef ZOMBIE_HPP
# include <iostream>
# include <string>
# include <vector>

class Zombie
{
  public:
    Zombie();

	Zombie(std::string name);

	~Zombie();

	void announce(void);

	void init_name(std::string zombie_name);

  private:
	std::string name;
};

void	randomChump(std::string name);
Zombie	*zombieHorde(int N, std::string name);

#endif // !ZOMBIE_H
