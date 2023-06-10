#pragma once
#ifndef FIND_SUBSTR_HPP

# include <fstream>
# include <iostream>
# include <iterator>
# include <sstream>
# include <string>

class SubstrReplace
{
  public:
	SubstrReplace(char *file, char *s1, char *s2);
	bool open_file(char *file);
	bool create_new_file();

  private:
	void find_and_replace();
	std::string filename;
	std::string newfile_name;
	std::string file_content;
	std::string str_to_remove;
	std::string str_to_add;
};

#endif // !FIND_SUBSTR_HPP
