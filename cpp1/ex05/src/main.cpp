#include "../inc/harl.hpp"
#include <iostream>

int main()
{
	Harl Mr_Harl;

	std::cout << "\n==== complain(\"n'importe qui\")" << std::endl;
	Mr_Harl.complain("n'importe qui");
	std::cout << "\n==== complain(\"n'importe quoi\")" << std::endl;
	Mr_Harl.complain("n'importe quoi");
	std::cout << "\n==== complain(" << DEBUG_STR << ")" << std::endl;
	Mr_Harl.complain(DEBUG_STR);
	std::cout << "\n==== complain(" << INFO_STR << ")" << std::endl;
	Mr_Harl.complain(INFO_STR);
	std::cout << "\n==== complain(" << WARN_STR << ")" << std::endl;
	Mr_Harl.complain(WARN_STR);
	std::cout << "\n==== complain(" << ERROR_STR << ")" << std::endl;
	Mr_Harl.complain(ERROR_STR);
	return 0;
}
