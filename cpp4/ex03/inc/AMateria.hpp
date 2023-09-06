#ifndef AMATERIA
#define AMATERIA

#include "Icharacter.hpp"
#include <iostream>

class AMateria
{
  private:
	std::string type;

  public:
	// coplien
	AMateria();
	AMateria(const AMateria &other);
	AMateria &operator=(const AMateria &other);
	~AMateria();

  protected:
	AMateria(std::string const &type);
	std::string const &getType() const; // Returns the materia type
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif // !AMATERIA
