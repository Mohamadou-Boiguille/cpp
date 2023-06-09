#include "../inc/contact.hpp"

void Contact::set_contact(std::string contact_array[])
{
	firstname = contact_array[FN];
	lastname = contact_array[LN];
	nickname = contact_array[NN];
	phone = contact_array[PH];
	secret = contact_array[SC];
}

void Contact::print_all_contact_infos()
{
	std::cout << "\nCONTACT INFOS\n";
	std::cout << "Firstname         : " << firstname << "\n";
	std::cout << "Lastname          : " << lastname << "\n";
	std::cout << "Nickname          : " << nickname << "\n";
	std::cout << "Phone             : " << phone << "\n";
	std::cout << "Darkest secret    : " << secret << "\n";
}

void Contact::print_research(std::string &element)
{
	if (element.length() < 10)
	{
		for (size_t i = 0; i < 10 - element.length(); i++)
			std::cout << " ";
	}
	for (size_t i = 0; i < 10 && i < element.length(); i++)
	{
		if (i == 9 && element.length() > 10)
			std::cout << ".";
		else
			std::cout << element.at(i);
	}
}

void Contact::print_contact_research()
{
	print_research(firstname);
	std::cout << "|";
	print_research(lastname);
	std::cout << "|";
	print_research(nickname);
	std::cout << std::endl;
}
