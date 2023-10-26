#include <iostream>
#include <exception>

#define RESET_COLOR "\033[0m"
#define BLACK_COLOR "\033[30m"
#define RED_COLOR "\033[31m"
#define GREEN_COLOR "\033[32m"
#define YELLOW_COLOR "\033[33m"
#define BLUE_COLOR "\033[34m"
#define MAGENTA_COLOR "\033[35m"
#define CYAN_COLOR "\033[36m"
#define WHITE_COLOR "\033[37m"
#define GREY_COLOR "\033[90m"

class FormGradeTooLowException : public std::exception
{
    public:
    FormGradeTooLowException(std::string bName, std::string fName, bool fCreate)
        : formName(fName), burName(bName), creation(fCreate){};
    virtual const char *what() const throw()
    {
        if (creation)
            message = std::string(RED_COLOR) + "Form '" + formName 
                + "' form can't be create, grade is too low" + RESET_COLOR;
        else
            message = std::string(RED_COLOR) + burName 
            + "'s grade is too low to sign " + formName + RESET_COLOR;
        return (message.c_str());
    }
    virtual ~FormGradeTooLowException() throw()
    {
    }

    private:
    std::string formName;
    std::string burName;
    bool creation;
    mutable std::string message;
};

class FormGradeTooHighException : public std::exception
{
    public:
    FormGradeTooHighException(std::string bName, std::string fName,
            bool fCreate)
        : formName(fName), burName(bName), creation(fCreate){};
    virtual const char *what() const throw()
    {
        if (creation)
            message = std::string(RED_COLOR) + "Form '" + formName 
                + "' form can't be create, grade is too high" + RESET_COLOR;
        return (message.c_str());
    }
    virtual ~FormGradeTooHighException() throw()
    {
    }

    private:
    std::string formName;
    std::string burName;
    bool creation;
    mutable std::string message;
};

class AlreadySigned : public std::exception
{
    public:
    virtual const char *what() const throw()
    {
        return ("Already signed");
    }
};

class GradeTooLowException : public std::exception
{
    public:
    GradeTooLowException(std::string bName) : bcratName(bName) {};
    virtual const char *what() const throw()
    {
        message = RED_COLOR + bcratName 
            + " couldn't have grade more than 150" + RESET_COLOR;
        return message.c_str();
    }
    virtual ~GradeTooLowException() throw()
    {
    }
    private:
    std::string bcratName;
    mutable std::string message;
};

class GradeTooHighException : public std::exception
{
    public:
    GradeTooHighException(std::string bName) : bcratName(bName) {};
    virtual const char *what() const throw()
    {
        message = RED_COLOR + bcratName 
            + " couldn't have grade less than 1" + RESET_COLOR;
        return message.c_str();
    }
    virtual ~GradeTooHighException() throw()
    {
    }
    private:
    std::string bcratName;
    mutable std::string message;
};

