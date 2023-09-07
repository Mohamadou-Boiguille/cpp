#pragma once

#include "../inc/Brain.hpp"
#include <iostream>
#include <string>
#include <typeinfo>

class Animal
{
  private:
	static int nextIndex;

  public:
	Animal();
	Animal(const std::string newType);
	Animal(const Animal &);
	Animal &operator=(const Animal &);
	virtual ~Animal();

	void makeSound(void) const;
	void setType(std::string newType);
	void setSound(std::string newSound);

	std::string getType() const;
	std::string getSound() const;
    int getIndex();

    virtual void getThought() = 0;

  protected:
	int index;
	std::string type;
	std::string sound;
};
