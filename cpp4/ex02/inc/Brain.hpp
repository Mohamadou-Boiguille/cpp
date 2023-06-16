#pragma once

#ifndef BRAIN_HPP
# include <iostream>

class Brain
{
  public:
	Brain();
	Brain(int index);
	Brain(const Brain &);
	Brain &operator=(const Brain &);
	~Brain();
	std::string getString(int index);
    void initStrings();

  private:
    std::string ideas[100];
	int index;
};
#endif // !BRAIN_HPP
