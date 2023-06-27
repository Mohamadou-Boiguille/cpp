#include "../inc/Harl.hpp"

int main (int argc, char **argv) {
    
    if (argc != 2)
    {
        std::cout << "Harl need one numeric parameter" << std::endl;
        return (0);
    }
    Harl filter;
    filter.complain(argv[1]);
    return 0;
}
