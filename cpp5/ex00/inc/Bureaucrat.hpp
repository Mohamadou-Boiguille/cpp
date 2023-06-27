#pragma once

#include <iostream>

class Bureaucrat
{
  public:
	Bureaucrat();
	Bureaucrat(std::string name, unsigned int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();
	std::string getName() const;
	unsigned int getGrade() const;
    void promote();
    void relegate();
    void gradeError(std::string action);
    void log(std::string action, unsigned int oldGrade);

  private:
	std::string name;
	unsigned int grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bcrat);

class GradeMax : public std::exception {
public:
    virtual const char * what() const throw()
    {
        return "promoted";
    }
};

class GradeMin : public std::exception {
public:
    virtual const char * what() const throw()
    {
        return "relegated";
    }
};
