#include "Zombie.h"
#include <vector>

Zombie	*zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (NULL);
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; i++)
    {
		horde[i].init_name(name);
    }
	// for (int i = 0; i < N; i++)
	return (horde);
}
