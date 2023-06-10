#include "../inc/harl.hpp"
#include <iostream>

int main () {
    
    Harl few_months_later;
    std::cout << "\n==== at the 'piscine :" << std::endl;
    few_months_later.complain("n'importe quoi");
    std::cout << "\n==== two months and Harl be like" << std::endl;
    few_months_later.complain(DEBUG_STR);
    std::cout << "\n==== three months and Harl be like" << std::endl;
    few_months_later.complain(INFO_STR);
    std::cout << "\n==== four months and Harl be like" << std::endl;
    few_months_later.complain(WARN_STR);
    std::cout << "\n==== five months and Harl be like" << std::endl;
    few_months_later.complain(ERROR_STR);
    return 0;
}
