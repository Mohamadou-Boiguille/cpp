#include "../inc/find_substr.hpp"
#include <iostream>

SubstrReplace::SubstrReplace(char *file, char *s1, char *s2)
	: filename(file), str_to_remove(s1), str_to_add(s2)
{
	if (filename.empty() || str_to_remove.empty() || str_to_add.empty())
	{
		if (str_to_remove.empty())
			std::cerr << "Empty substring to find" << std::endl;
		if (str_to_add.empty())
			std::cerr << "Empty substring to replace" << std::endl;
		if (filename.empty())
			std::cerr << "No file name specified" << std::endl;
		return ;
	}
	if (!open_file(file))
		return ;
	find_and_replace();
}

bool SubstrReplace::open_file(char *file)
{
	std::ifstream test_file(file);
	std::ostringstream oss;
	if (!test_file.is_open())
	{
		std::cout << "file opening failed" << std::endl;
		return (false);
	}
	else
		oss << test_file.rdbuf();
	file_content = oss.str();
	test_file.close();
	if (file_content.empty())
	{
		std::cout << filename << " is empty" << std::endl;
		return (false);
	}
	newfile_name = filename + ".replace";
	return (true);
}

void SubstrReplace::find_and_replace()
{
	size_t	index;

	index = file_content.find(str_to_remove);
	if (index == std::string::npos)
	{
		std::cout << "The given substring is not in the file" << std::endl;
		return ;
	}
	while (index != std::string::npos)
	{
		file_content.erase(index, str_to_remove.length());
		file_content.insert(index, str_to_add);
		index = file_content.find(str_to_remove);
	}
	create_new_file();
	// std::cout << file_content;
}

bool SubstrReplace::create_new_file()
{
	std::ofstream new_file(newfile_name.c_str());
	if (!new_file.is_open())
	{
		std::cerr << "New file creation failed" << std::endl;
		return (false);
	}
	new_file << file_content;
	new_file.close();
	return (true);
}
