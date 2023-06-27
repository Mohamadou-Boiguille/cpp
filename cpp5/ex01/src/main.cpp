#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"
#include <ostream>

int main (void) {
    Bureaucrat *Marc;
    Bureaucrat *Jeanne;
    Bureaucrat *noName;
    Bureaucrat *noRank;
    Bureaucrat *noRankTwo;
    (void)noRank;
    (void)noRankTwo;
    std::cout << "\n==== created Bureaucrats ====" << std::endl;
    try {
        std::cout << "new Bureaucrat(\"Marc\", 4)" << std::endl;
        Marc = new Bureaucrat("Marc", 4);
    } catch (std::exception &e) {
        std::cout << e.what() <<std::endl;
    }
    try {
        std::cout << "new Bureaucrat(\"Jeanne\", 147)" << std::endl;
        Jeanne = new Bureaucrat("Jeanne", 147);
    } catch (std::exception &e) {
        std::cout << e.what() <<std::endl;
    }
    try {
        std::cout << "new Bureaucrat(\"\", 147)" << std::endl;
        noName = new Bureaucrat("", 147);
    } catch (std::exception &e) {
        std::cout << e.what() <<std::endl;
    }
    try {
        std::cout << "new Bureaucrat(\"'0 Grade'\", 0)" << std::endl;
        noRank = new Bureaucrat("'0 Grade'", 0);
    } catch (std::exception &e) {
        std::cout << e.what() <<std::endl;
    }
    try {
        std::cout << "new Bureaucrat(\"'151 Grade'\", 151)" << std::endl;
        noRankTwo = new Bureaucrat("'151 Grade'", 151);
    } catch (std::exception &e) {
        std::cout << e.what() <<std::endl;
    }

    std::cout << "\n==== << operator ====" << std::endl;
    std::cout << GREEN_COLOR << *Marc << RESET_COLOR;
    std::cout << GREEN_COLOR << *Jeanne << RESET_COLOR;
    std::cout << GREEN_COLOR << *noName << RESET_COLOR;

    std::cout << "\n==== create Forms ====" << std::endl;
    Form *form[5];
    try {
        std::cout << "new Form(\"Contract_A\", 5, 10)" << std::endl;
        form[0] = new Form("Contract_A", 5, 10);
    } catch (std::exception &e) {
        std::cout << e.what() <<std::endl;
    }
    try {
        std::cout << "new Form(\"Contract_B\", 148, 147)" << std::endl;
        form[1] = new Form("Contract_B", 148, 147);
    } catch (std::exception &e) {
        std::cout << e.what() <<std::endl;
    }
    try {
        std::cout << "new Form(\"Contract_C\", 146, 3)" << std::endl;
        form[2] = new Form("Contract_C", 146, 3);
    } catch (std::exception &e) {
        std::cout << e.what() <<std::endl;
    }
    try {
        std::cout << "new Form(\"Contract_D\", 0, 3)" << std::endl;
        form[3] = new Form("Contract_D", 0, 3);
    } catch (std::exception &e) {
        std::cout << e.what() <<std::endl;
    }
    try {
        std::cout << "new Form(\"Contract_E\", 3, 151)" << std::endl;
        form[4] = new Form("Contract_E", 3, 151);
    } catch (std::exception &e) {
        std::cout << e.what() <<std::endl;
    }
    std::cout << "\n==== sign Forms ====" << std::endl;
    try {
        form[0]->beSigned(Jeanne);
    } catch (std::exception &e) {
        std::cout << e.what() <<std::endl;
    }
    try {
        form[0]->beSigned(Marc);
    } catch (std::exception &e) {
        std::cout << e.what() <<std::endl;
    }
    try {
        form[1]->beSigned(Jeanne);
    } catch (std::exception &e) {
        std::cout << e.what() <<std::endl;
    }
    (*Jeanne).signForm(form[2]);
    (*Jeanne).promote();
    (*Jeanne).signForm(form[2]);
    (*noName).signForm(form[2]);
    (*noName).promote();
    (*noName).signForm(form[2]);
    delete Marc;
    delete Jeanne;
    delete noName;
    for (int i = 0; i < 3; i++) {
        delete form[i];
    }
    return 0;
}
