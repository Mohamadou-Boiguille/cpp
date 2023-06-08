#pragma once
#ifndef ZOMBIE_HPP
# include <iostream>
# include <string>
# include <vector>

class Zombie
{
  public:
	Zombie(std::string name)
	{
		init_name(name);
	}

	~Zombie();

	void announce(void)
	{
		std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	}

	void init_name(std::string zombie_name)
	{
		name = zombie_name;
	}

  private:
	std::string name;
};

void	randomChump(std::string name);
Zombie	*zombieHorde(int N, std::string name);

#endif // !ZOMBIE_H
