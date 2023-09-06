#include "AMateria.hpp"

class Cure
{
  public:
	Cure();
	Cure(const Cure &other);
	Cure &operator=(const Cure &other);
	~Cure();
	AMateria clone();

  private:
};

AMateria Cure::clone()
{
}

Cure::Cure()
{
}

Cure::Cure(const Cure &other)
{
	*this = other;
}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
	}
	return *this;
}

Cure::~Cure()
{
}
