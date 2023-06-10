#pragma once
#ifndef HARL_HPP

# define DEBUG 0
# define INFO 1
# define WARN 2
# define ERROR 3
# define BAD_INPUT 4
# define DEBUG_STR "DEBUG"
# define INFO_STR "INFO"
# define WARN_STR "WARNING"
# define ERROR_STR "ERROR"

# include <iostream>
# include <string>

class Harl
{
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	std::string msg[5];

  public:
	Harl();
	void complain(std::string level);
};

#endif // !HARL_HPP
