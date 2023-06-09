#pragma once
#ifndef CONTACT_H
# define CONTACT_H

# define FN 0
# define LN 1
# define NN 2
# define PH 3
# define SC 4
# define HOME 42

# include <iostream>
# include <sstream>
# include <string>

class Contact
{
  public:
	void set_contact(std::string contact_array[]);
	void print_all_contact_infos();
	void print_contact_research();

  private:
	void print_research(std::string &element);
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phone;
	std::string secret;
};

#endif // !CONTACT_H
