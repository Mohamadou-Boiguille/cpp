#include "../inc/Form.hpp"
#include "../inc/Exceptions.hpp"

Form ::Form()
{
}
Form ::Form(std::string name, unsigned int minSign, unsigned int minExec)
	: name(name), isFormSigned(false), minExec(minExec), minSign(minSign)
{
    if (minSign == 0 || minExec == 0)
		throw FormGradeTooHighException("", getName(), true);
    else if (minSign > 150 || minExec > 150)
		throw FormGradeTooLowException("", getName(), true);
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
        this->isFormSigned = other.isFormSigned;
        this->minSign = other.minSign;
        this->minExec = other.minExec;
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
		throw FormGradeTooLowException(bcrat->getName(), getName(), false);
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
