#include <iostream>


int main(void)
{
    std::string leo_is_the_best = "HI THIS IS BRAIN";
    std::string *stringPTR = &leo_is_the_best;
    std::string &stringREF = leo_is_the_best;

    std::cout << "l'adresse de la string \"" << leo_is_the_best << "\" est : " << static_cast<void*>(&leo_is_the_best) << std::endl;
    std::cout << "l'adresse stockee dans \"stringPTR\" est : " << static_cast<void*>(stringPTR) << std::endl;
    std::cout << "l'adresse stockee dans \"stringREF\" est : " << static_cast<void*>(&stringREF) << std::endl;
    //
    std::cout << "la valeur de la string est : " << leo_is_the_best << std::endl;
    std::cout << "la valeur pointee par stringPTR est : " << *stringPTR << std::endl;
    std::cout << "la valeur pointee par stringREF est : " << stringREF << std::endl;
    return (0);
}
