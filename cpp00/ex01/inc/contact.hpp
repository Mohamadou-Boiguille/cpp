#pragma once
#ifndef CONTACT_H
#define CONTACT_H

#define FN 0
#define LN 1
#define NN 2
#define PH 3
#define SC 4
#define HOME 42

#include <iostream>
#include <sstream>
#include <string>

class Contact
{
  public:
	void setContact(std::string contactArray[]);
	void printContact();
	void printSearch();

  private:
	void printCategory(std::string &element);
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phone;
	std::string secret;
};

#endif // !CONTACT_H
