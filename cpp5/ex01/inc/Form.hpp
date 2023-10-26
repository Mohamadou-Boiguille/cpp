#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class	Bureaucrat;
class Form
{
  public:
	Form();
	Form(std::string name, unsigned int minSign, unsigned int minExec);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();
	unsigned int getMinSign();
	unsigned int getMinExec();
	bool getIfSigned();
	std::string getName();
	void beSigned(Bureaucrat *bcrat);

  private:
	const std::string name;
	bool isFormSigned;
	unsigned int minExec;
	unsigned int minSign;
};

#endif // !FORM_HPP
