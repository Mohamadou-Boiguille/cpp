#include "../inc/Icharacter.hpp"
#include "Icharacter.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
	}
	return *this;
}

AMateria::~AMateria()
{
}
