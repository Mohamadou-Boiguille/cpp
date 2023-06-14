#pragma once
#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>
# include <string>

class Dog : public Animal
{
  public:
	Dog();
	Dog(const Dog &);
	Dog &operator=(const Dog &);
	~Dog();
	std::string getTypeName() const;

  private:
	Brain *ideas;
};

#endif // !ANIMAL_HPP
