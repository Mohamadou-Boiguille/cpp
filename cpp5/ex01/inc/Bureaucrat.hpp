#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

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
# include <iostream>

class	Form;
class Bureaucrat
{
  public:
	Bureaucrat();
	Bureaucrat(const std::string name, unsigned int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();
	const std::string getName() const;
	unsigned int getGrade() const;
    void promote();
    void relegate();
    void gradeError(std::string action);
    void log(std::string action, unsigned int oldGrade);
    void signForm(Form *toSign);

  private:
	const std::string name;
	unsigned int grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bcrat);

#endif // !BUREAUCRAT_HPP
