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
	size_t nb_of_contacts;
	void print_research(std::string &element);
	size_t getValidIndex();
	void store_contact_infos(std::string &info, std::string str);
	void choose_contact();
};

#endif // !PHONEBOOK_H
