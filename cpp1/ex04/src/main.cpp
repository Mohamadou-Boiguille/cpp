#include "../inc/find_substr.hpp"

int invalid_msg(void)
{
    std::cout << "Program need 3 valid paramaters" << std::endl;
    return (2);
}

int	main(int argc, char **argv)
{
    std::string file;
    std::string s1;
    std::string s2;

	if (argc != 4)
        return invalid_msg();
    SubstrReplace rep(argv[1], argv[2], argv[3]);
	return (0);
}
