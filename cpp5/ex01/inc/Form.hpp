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
	class GradeTooLowException : public std::exception
	{
		public:
		GradeTooLowException(std::string bName, std::string fName, bool fCreate)
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
		virtual ~GradeTooLowException() throw()
		{
		}

		private:
		std::string formName;
		std::string burName;
		bool creation;
		mutable std::string message;
	};

	class GradeTooHighException : public std::exception
	{
		public:
		GradeTooHighException(std::string bName, std::string fName,
				bool fCreate)
			: formName(fName), burName(bName), creation(fCreate){};
		virtual const char *what() const throw()
		{
			if (creation)
				message = std::string(RED_COLOR) + "Form '" + formName 
                    + "' form can't be create, grade is too high" + RESET_COLOR;
			return (message.c_str());
		}
		virtual ~GradeTooHighException() throw()
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

  private:
	const std::string name;
	bool isFormSigned;
	unsigned int minExec;
	unsigned int minSign;
};

#endif // !FORM_HPP
