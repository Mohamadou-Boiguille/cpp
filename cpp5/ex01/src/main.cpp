#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"
#include <cstring>
#include <iostream>
#include <ostream>
#include <sstream>

Bureaucrat *announce(std::string name, int rank)
{
    std::cout << GREEN_COLOR << "Execute :new Bureaucrat(" << name << ", " << rank << ")" << std::endl;
    Bureaucrat *somebody = new Bureaucrat(name, rank);
    std::string reply = GREY_COLOR  ;
    reply.append("this->getName() :");  
    reply.append(somebody->getName());
    reply.append( "\n");
    std::ostringstream gradeStream;
    gradeStream << somebody->getGrade();
    reply.append("this->getGrade() :");  
    reply.append(gradeStream.str());
    reply.append(RESET_COLOR);
    std::cout << reply << std::endl;
    return somebody;
}

Form *createForms(std::string formName, int requiredSign, int requiredExec)
{
    Form * form;
    std::cout << "Execute :new Form(\"" << formName << " ," << requiredSign << " ," << requiredExec << ")" << std::endl;
    try {
        form = new Form(formName, requiredSign, requiredExec);
    } catch (std::exception &e) {
        std::cout << e.what() <<std::endl;
    }
    return form;
}


void signForms(Form *form, Bureaucrat *bureaucrat)
{
    std::cout << "Execute :" << form->getName() << "->beSigned(" << bureaucrat->getName() << ")" << std::endl;
    try {
        form->beSigned(bureaucrat);
    } catch (std::exception &e) {
        std::cout << e.what() <<std::endl;
    }
}

int main (void) {
    std::cout << "\n==== created Bureaucrats ====" << std::endl;
    std::string initNames[5] = {"Marc", "Jeanne", "", "GradeAt0", "GradeAt151"};
    int initGrades[5] = {4, 147, 147, 0, 151};
    Bureaucrat *bureaucratArray[5];
    for (int i = 0; i < 5; i++)
        bureaucratArray[i] = announce(initNames[i], initGrades[i]);

    std::cout << "\n==== << operator ====" << std::endl;
    for  (int i = 0; i < 5; i++)
        std::cout << GREEN_COLOR << *bureaucratArray[i] << RESET_COLOR;

    std::cout << "\n==== create Forms ====" << std::endl;
    std::string strArr[5] = {"FormA", "FormB", "FormC", "FormD", "FormE"};
    int requiredSign[5] = {15, 148, 146, 0, 3};
    int requiredExec[5] = {15, 147, 3, 3, 151};
    Form *formArr[5];
    memset(formArr, 0, 5 * sizeof(Form *));
    for (int i = 0; i < 5; i++)
        formArr[i] = createForms(strArr[i], requiredSign[i], requiredExec[i]);
    std::cout << "\n==== sign Forms ====" << std::endl;
    for (int i = 0; i < 5; i++)
        signForms(formArr[i], bureaucratArray[i]);
    for (int i = 0; i < 3; i++) {
        delete bureaucratArray[i];
    }
    return 0;
}
