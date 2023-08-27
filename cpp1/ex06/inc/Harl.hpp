#pragma once
#include <iostream>
#include <string>
#ifndef HARL_HPP

#define DEBUG 0
#define INFO 1
#define WARN 2
#define ERROR 3
#define BAD_INPUT 4
#define DEBUG_STR "DEBUG"
#define INFO_STR "INFO"
#define WARN_STR "WARNING"
#define ERROR_STR "ERROR"

#include <iostream>

class Harl
{
	std::string level_strs[4];
	std::string get_complain_str(std::string level);
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

  public:
	Harl();
	std::string get_type(int level);
	void complain(std::string level);
	void filter(std::string level);
};

#endif // !HARL_HPP
