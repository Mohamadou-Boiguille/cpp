#include "AMateria.hpp"

class Ice
{
  public:
	Ice();
	Ice(const Ice &other);
	Ice &operator=(const Ice &other);
	~Ice();
	AMateria clone();

  private:
};

AMateria Ice::clone()
{
}

Ice::Ice()
{
}

Ice::Ice(const Ice &other)
{
	*this = other;
}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
	}
	return *this;
}

Ice::~Ice()
{
}
