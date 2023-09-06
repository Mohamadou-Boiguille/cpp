#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal
{
  public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal &);
	WrongAnimal &operator=(const WrongAnimal &);
	~WrongAnimal();
	void makeSound() const;
	std::string getType() const;

  protected:
	void setSound(const std::string &sound);
	std::string _type;
	std::string _sound;
};

#endif // WRONGANIMAL_HPP