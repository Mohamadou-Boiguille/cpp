#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"
#include <exception>
#include <iostream>
#include <sstream>

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade)
	: name(name.empty() ? "John Doe" : name), grade(grade)
{
    if (grade == 0)
        throw GradeTooHighException(this->getName());
    else if (grade > 150)
        throw GradeTooLowException(this->getName());
    else
    {
        std::cout << GREY_COLOR << this->name << " (Grade ";
        std::cout << this->grade << ") is created." << RESET_COLOR;
        std::cout << std::endl;
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: name(other.name), grade(other.grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->grade = other.grade;
		this->name = other.name;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bcrat)
{
    os << bcrat.getName() << ", bureaucrat grade " << bcrat.getGrade() << std::endl;
    return os;
}

Bureaucrat::~Bureaucrat()
{
	// Destructor implementation
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::log(std::string action, unsigned int oldGrade)
{
    std::cout << name << " is " << action;
    std::cout << " from grade " << oldGrade;
    std::cout << " to " << getGrade() << std::endl;
}

void Bureaucrat::promote()
{
    if (this->grade <= 1)
        throw GradeTooHighException(this->getName());
    this->grade -= 1;
    log("promoted", this->grade + 1);
}

void Bureaucrat::gradeError(std::string action)
{
	std::cout << this->name << " is at grade " << getGrade();
	std::cout << " and cannot be " << action << "." << std::endl;
}

void Bureaucrat::relegate()
{
    if (this->grade >= 150)
        throw GradeTooLowException(this->getName());
    this->grade += 1;
    log("relegate", this->grade - 1);
}

void Bureaucrat::signForm(Form *toSign)
{
    try {
        toSign->beSigned(this);
    } catch (std::exception &e) {
        std::cout << e.what() <<std::endl;
        return;
    }
    std::cout << GREEN_COLOR;
    std::cout << this->getName() << " signed " << toSign->getName();
    std::cout << RESET_COLOR << std::endl;
}
