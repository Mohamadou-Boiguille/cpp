#pragma once
#ifndef ZOMBIE_HPP
# include <iostream>
# include <string>

class Zombie
{
  public:
	void announce(void)
	{
		std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	}

    Zombie(std::string name)
    {
        init_name(name);
    }

    ~Zombie()
    {
        std::cout << name << " has been deleted" << std::endl;
    }

  private:
	std::string name;

    void init_name(std::string zombie_name)
    {
        name = zombie_name;
    }
};

void randomChump(std::string name);

#endif // !ZOMBIE_H
