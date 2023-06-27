#include "../inc/Bureaucrat.hpp"

int main (void) {
    Bureaucrat dude("Marc", 4);

    std::cout << "=== << operator test ===" << std::endl;
    std::cout << dude;
    for (int i = 0; i < 5; i++) {
        std::cout << "=== promote " << i << "===" << std::endl;
        try
        {
            dude.promote();
        }
        catch (std::exception &e)
        {
            std::cout << "---> ERROR : ";
            dude.gradeError(e.what());
        }
    }

    Bureaucrat pow("Jeanne", 147);

    std::cout << "=== << operator test ===" << std::endl;
    std::cout << pow;
    for (int i = 0; i < 5; i++) {
        std::cout << "=== relagate " << i << "===" << std::endl;
        try
        {
            pow.relegate();
        }
        catch (std::exception &e)
        {
            std::cout << "---> ERROR : ";
            pow.gradeError(e.what());
        }
    }
    return 0;
}
