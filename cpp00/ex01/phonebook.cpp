#include <cctype>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

class Contact
{
  public:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phone;
	std::string secret;
};

class PhoneBook
{
 //  public:
	// PhoneBook();

  private:
	Contact book[8];

	size_t nb_of_contacts;

	void print_research(std::string &element)
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

	void print_contact(size_t index)
	{
		std::cout << "\nCONTACT INFOS\n"
					<< book[index].firstname << "\n";
		std::cout << "Firstname         : " << book[index].firstname << "\n";
		std::cout << "Lastname          : " << book[index].lastname << "\n";
		std::cout << "Nickname          : " << book[index].nickname << "\n";
		std::cout << "Phone             : " << book[index].phone << "\n";
		std::cout << "Darkest secret    : " << book[index].secret << "\n";
	}

	size_t getValidIndex()
	{
		std::string input;
		int index = 42;

		while (!std::cin.eof())
		{
			std::cout << "Please contact index (Enter 'home' to quit this menu) : ";
			std::getline(std::cin, input);

			if (input == "home" || input == "HOME")
				break ;
			std::istringstream convert(input);
			if (convert >> index)
			{
				if (index >= 0 && index < static_cast<int>(nb_of_contacts))
					return (static_cast<size_t>(index));
				if (index >= 8 || index < 0)
					std::cout << "Contact memory is limited to 8 contacts (0 to 7)\n";
				else
					std::cout << "No Contact at index " << index << "\n";
			}
			else
				std::cout << "Wrong format - Enter a number\n";
		}
		return (static_cast<size_t>(index));
	}

	void choose_contact()
	{
		size_t contact_index;

		contact_index = getValidIndex();
		if (contact_index == 42)
			return ;
		else if (contact_index >= nb_of_contacts)
			choose_contact();
		else
			print_contact(contact_index);
	}

	void get_info(std::string &info, const char str[])
	{
        info = "";
        while (!std::cin.eof() && info.empty())
         {
            info = "";
            std::cout << str;
            std::getline(std::cin, info);
            // std::cout << info;
        }
	}

  public:
	void init()
	{
		nb_of_contacts = 0;
	}

	void search()
	{
		size_t i = 0;
		if (nb_of_contacts == 0)
		{
			std::cout << "No contact" << std::endl;
			return ;
		}
		std::cout << "\nINDEX     |";
		std::cout << "FIRSTNAME |";
		std::cout << "LASTNAME  |";
		std::cout << "NICKNAME" << std::endl;
		while (i < nb_of_contacts)
		{
			std::cout << "         ";
			std::cout << i << "|";
			print_research(book[i].firstname);
			std::cout << "|";
			print_research(book[i].lastname);
			std::cout << "|";
			print_research(book[i].nickname);
			std::cout << std::endl;
			i++;
		}
		std::cout << "\n";
		if (nb_of_contacts)
			choose_contact();
	}

	void add()
	{
		static size_t oldest_index;
		std::string element;

		std::cout << "\nNEW CONTACT\n";
        get_info(book[oldest_index].firstname, "Firstname : ");
		get_info(book[oldest_index].lastname, "Lastname : ");
		get_info(book[oldest_index].nickname, "Nickname : ");
		get_info(book[oldest_index].phone, "Phone : ");
		get_info(book[oldest_index].secret, "Darkest secret : ");
		oldest_index++;
		if (oldest_index == 8)
			oldest_index = 0;
		if (nb_of_contacts < 8)
			nb_of_contacts++;
	}
};

int	main(void)
{
	PhoneBook	phone_book;

	phone_book.init();
	std::string input;
	while (!std::cin.eof() && input != "EXIT" && input != "e")
	{
		std::cout << "\nBLACKMAIL PHONEBOOK" << std::endl;
		std::cout << "you can type : 'ADD', 'SEARCH' or 'EXIT' : \n";
		std::getline(std::cin, input);
		if (input == "ADD" || input == "a")
			phone_book.add();
		else if (input == "SEARCH" || input == "s")
			phone_book.search();
		else if (input == "")
			continue ;
	}
	return (0);
}
