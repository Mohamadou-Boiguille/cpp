#include <iostream>

bool	ft_islower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (true);
	return (false);
}

int	main(int argc, char *argv[])
{
	char	*str;
	size_t	i;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	i = 1;
	while (i < argc)
	{
		str = argv[i];
		if (i > 1)
			std::cout << " ";
		while (*str)
		{
			if (ft_islower(*str))
				*str -= 32;
			std::cout << *str;
			str++;
		}
		i++;
	}
	std::cout << "\n" << std::endl;
	return (0);
}
