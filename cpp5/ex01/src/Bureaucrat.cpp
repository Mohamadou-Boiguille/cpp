#include "../inc/Bureaucrat.hpp"
#include "../inc/Exceptions.hpp"
#include "../inc/Form.hpp"
#include <exception>
#include <iostream>
#include <sstream>

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade)
	: name(name.empty() ? "Uknown" : name), grade(grade)
{
    if (grade > 150 || grade < 1)
    {
        std::cerr << RED_COLOR << grade << " is a wrong grade, put to lowest possible grade (150)" << RESET_COLOR << std::endl;
        this->grade = 150;
    }
    else
        this->grade = grade;
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
}

const std::string Bureaucrat::getName() const
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
