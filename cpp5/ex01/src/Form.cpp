#include "../inc/Form.hpp"

Form ::Form()
{
}
Form ::Form(std::string name, unsigned int minSign, unsigned int minExec)
	: name(name), isFormSigned(false), minExec(minExec), minSign(minSign)
{
    if (minSign == 0 || minExec == 0)
		throw GradeTooHighException("", getName(), true);
    else if (minSign > 150 || minExec > 150)
		throw GradeTooLowException("", getName(), true);
    else
    {
        std::cout << GREY_COLOR;
        std::cout << "Form '" << name << "' is created ";
        std::cout << "- Sign Grade : " << minSign;
        std::cout << " - Execute grade : " << minExec;
        std::cout << std::endl;
        std::cout << RESET_COLOR;
    }
}

Form ::Form(const Form &other)
	: name(other.name), isFormSigned(other.isFormSigned), minExec(other.minExec),
		minSign(other.minSign)
{
}
Form &Form ::operator=(const Form &other)
{
	if (this != &other)
	{
	}
	return (*this);
}

Form ::~Form()
{
}
unsigned int Form ::getMinSign()
{
	return (this->minSign);
}
unsigned int Form ::getMinExec()
{
	return (this->minExec);
}
bool Form ::getIfSigned()
{
	return (this->isFormSigned);
}
std::string Form ::getName()
{
	return (this->name);
}
void Form ::beSigned(Bureaucrat *bcrat)
{
	if (bcrat->getGrade() > this->getMinSign())
		throw GradeTooLowException(bcrat->getName(), getName(), false);
    if (this->isFormSigned == true)
    {
        std::cout << GREY_COLOR << this->getName();
        std::cout << " is already signed." << RESET_COLOR << std::endl;
        throw AlreadySigned();
    }
    std::cout << GREY_COLOR << bcrat->getName() << " signed ";
    std::cout << this->getName() << "." << RESET_COLOR << std::endl;
	this->isFormSigned = true;
}
