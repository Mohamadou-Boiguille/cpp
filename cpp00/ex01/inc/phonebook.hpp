#pragma once
#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "contact.hpp"

class PhoneBook
{
  public:
	PhoneBook();
	void search();
	void add();
  private:
	Contact book[8];
	size_t nbContacts;
	// void print_research(std::string &element);
	size_t getValidIndex();
	void storeContact(std::string &info, std::string str);
	void chooseContact();
};

#endif // !PHONEBOOK_H
