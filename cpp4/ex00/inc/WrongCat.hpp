#ifndef WRONGCAT_CPP
# define WRONGCAT_CPP

# include "WrongAnimal.hpp"
# include <iostream>

class WrongCat : public WrongAnimal
{
  public:
	WrongCat();
	WrongCat(const WrongCat &);
	WrongCat &operator=(const WrongCat &);
	virtual ~WrongCat();
};

#endif //WRONGCAT_CPP