#include "../inc/phonebook.hpp"
#include <cctype>

PhoneBook::PhoneBook()
{
	nbContacts = 0;
}

void PhoneBook::search()
{
	size_t	i;

	i = 0;
	if (nbContacts == 0)
	{
		std::cout << "No contact" << std::endl;
		return ;
	}
	std::cout << "\nINDEX     |FIRSTNAME |LASTNAME  |NICKNAME" << std::endl;
	while (i < nbContacts)
	{
		std::cout << "         " << i << "|";
		book[i++].printSearch();
	}
	std::cout << "\n";
	if (nbContacts)
		chooseContact();
}

size_t PhoneBook::getValidIndex()
{
	int	index = -1;
	std::string input;

	while (!std::cin.eof())
	{
        input = "";
		std::cout << "Enter contact index (Enter 'home' to quit) : ";
		std::getline(std::cin, input);
		if (input == "home" || input == "HOME")
		{
			std::cout << "Contact search canceled\n";
			break ;
		}
		std::istringstream convert(input);
		if (convert >> index && index >= 0)
		{
			if (index < static_cast<int>(nbContacts))
				return (static_cast<size_t>(index));
			if (index >= 8)
				std::cout << "Memory is limited to 8 contacts (0 to 7)\n";
			else
				std::cout << "No Contact at index " << index << "\n";
		}
	}
	return (static_cast<size_t>(index));
}

void PhoneBook::storeContact(std::string &info, std::string str)
{
	info = "";
	while (!std::cin.eof() && info.empty())
	{
		info = "";
		std::cout << str;
		std::getline(std::cin, info);
        if (info == "home" || info == "HOME")
            return;
        if (str == "Phone : ")
        {
            for (std::string::const_iterator it = info.begin(); it != info.end(); it++)
            {
                if(!std::isdigit(*it))
                {
                    std::cout << "Only digits for a phone number" << std::endl;
                    info = "";
                    break;
                }
            }
        }
	}
}

void PhoneBook::add()
{
	static size_t	oldestIndex;

	std::string element[] = {"Firstname : ", "Lastname : ", "Nickname : ",
		"Phone : ", "Darkest secret : "};
	std::string infos[5];
	std::cout << "\nNEW CONTACT (Enter : 'home' to quit)\n";
	for (int i = 0; i < 5; i++)
	{
		storeContact(infos[i], element[i]);
		if (infos[i] == "home" || infos[i] == "HOME")
		{
			std::cout << "Contact creation canceled\n";
			return ;
		}
	}
	book[oldestIndex++].setContact(infos);
	oldestIndex %= 8;
	if (nbContacts < 8)
		nbContacts++;
}

void PhoneBook::chooseContact(void)
{
	size_t	contactIndex;

	contactIndex = getValidIndex();
	if (contactIndex == HOME)
		return ;
	else if (contactIndex >= nbContacts)
		chooseContact();
	else
		book[contactIndex].printContact();
}
