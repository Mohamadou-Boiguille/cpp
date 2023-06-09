#include "../inc/phonebook.hpp"

PhoneBook::PhoneBook()
{
	nb_of_contacts = 0;
}

void PhoneBook::search()
{
	size_t	i;

	i = 0;
	if (nb_of_contacts == 0)
	{
		std::cout << "No contact" << std::endl;
		return ;
	}
	std::cout << "\nINDEX     |FIRSTNAME |LASTNAME  |NICKNAME" << std::endl;
	while (i < nb_of_contacts)
	{
		std::cout << "         " << i << "|";
		book[i++].print_contact_research();
	}
	std::cout << "\n";
	if (nb_of_contacts)
		choose_contact();
}

size_t PhoneBook::getValidIndex(void)
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
			if (index < static_cast<int>(nb_of_contacts))
				return (static_cast<size_t>(index));
			if (index >= 8)
				std::cout << "Contact memory is limited to 8 contacts (0 to 7)\n";
			else
				std::cout << "No Contact at index " << index << "\n";
		}
		else
			std::cout << "Wrong format - Enter an index (0 to 7)\n";
	}
	return (static_cast<size_t>(index));
}

void PhoneBook::store_contact_infos(std::string &info, std::string str)
{
	info = "";
	while (!std::cin.eof() && info.empty())
	{
		info = "";
		std::cout << str;
		std::getline(std::cin, info);
	}
}

void PhoneBook::add()
{
	static size_t	oldest_index;

	std::string element[] = {"Firstname : ", "Lastname : ", "Nickname : ",
		"Phone : ", "Darkest secret : "};
	std::string infos[5];
	std::cout << "\nNEW CONTACT (Enter : 'home' to quit)\n";
	for (int i = 0; i < 5; i++)
	{
		store_contact_infos(infos[i], element[i]);
		if (infos[i] == "home" || infos[i] == "HOME")
		{
			std::cout << "Contact creation canceled\n";
			return ;
		}
	}
	book[oldest_index++].set_contact(infos);
	oldest_index %= 8;
	if (nb_of_contacts < 8)
		nb_of_contacts++;
}

void PhoneBook::choose_contact(void)
{
	size_t	contact_index;

	contact_index = getValidIndex();
	if (contact_index == HOME)
		return ;
	else if (contact_index >= nb_of_contacts)
		choose_contact();
	else
		book[contact_index].print_all_contact_infos();
}
