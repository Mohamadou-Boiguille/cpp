#include "../inc/contact.hpp"

void Contact::setContact(std::string contactArray[])
{
	firstname = contactArray[FN];
	lastname = contactArray[LN];
	nickname = contactArray[NN];
	phone = contactArray[PH];
	secret = contactArray[SC];
}

void Contact::printContact()
{
	std::cout << "\nCONTACT INFOS\n";
	std::cout << "Firstname         : " << firstname << "\n";
	std::cout << "Lastname          : " << lastname << "\n";
	std::cout << "Nickname          : " << nickname << "\n";
	std::cout << "Phone             : " << phone << "\n";
	std::cout << "Darkest secret    : " << secret << "\n";
}

void Contact::printCategory(std::string &element)
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

void Contact::printSearch()
{
	printCategory(firstname);
	std::cout << "|";
	printCategory(lastname);
	std::cout << "|";
	printCategory(nickname);
	std::cout << std::endl;
}
