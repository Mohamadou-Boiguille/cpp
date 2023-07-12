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
	std::cout << std::endl;
	std::cout << "CONTACT INFOS" << std::endl;
	std::cout << "Firstname         : " << firstname << std::endl;
	std::cout << "Lastname          : " << lastname << std::endl;
	std::cout << "Nickname          : " << nickname << std::endl;
	std::cout << "Phone             : " << phone << std::endl;
	std::cout << "Darkest secret    : " << secret << std::endl;
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
