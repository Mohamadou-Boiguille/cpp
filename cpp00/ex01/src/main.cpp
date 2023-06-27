#include "../inc/phonebook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;

	std::string input;
	while (!std::cin.eof() && input != "EXIT"/*  && input != "e" */)
	{
		std::cout << "\nBLACKMAIL PHONEBOOK" << std::endl;
		std::cout << "you can type : 'ADD', 'SEARCH' or 'EXIT' : \n";
		std::getline(std::cin, input);
		if (input == "ADD"/*  || input == "a" */)
			phoneBook.add();
		else if (input == "SEARCH"/*  || input == "s" */)
			phoneBook.search();
		else if (input == "")
			continue ;
	}
	return (0);
}
