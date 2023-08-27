#include "../inc/Harl.hpp"
#include <string>

Harl::Harl(void)
{
	level_strs[0] = "DEBUG";
	level_strs[1] = "INFO";
	level_strs[2] = "WARNING";
	level_strs[3] = "ERROR";
}

void Harl::complain(std::string level)
{
	void (Harl::*level_log[4])(void) = {
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++)
	{
		if (level == level_strs[i])
			return (this->*level_log[i])();
	}
	std::cout << "ERROR: BAD INPUT" << std::endl;
}

void Harl::debug(void)
{
	std::cout << "== DEBUG ==" << std::endl;
	std::cout << "I can't believe I have to spend countless hours deciphering \
cryptic coding puzzles at 42. It's like solving a never-ending maze \
without any clear direction. Frustrating, isn't it?"
			  << std::endl;
}

void Harl::info(void)
{
	std::cout << "== INFO ==" << std::endl;
	std::cout << "I'm extremely disappointed with the lack of resources \
provided by 42. It's like they expect us to magically acquire knowledge \
without proper guidance. How can they expect us to succeed?"
			  << std::endl;
}

void Harl::warning(void)
{
	std::cout << "== WARNING ==" << std::endl;
	std::cout << "I've been at 42 for a while now, and I think it's unfair \
that they keep accepting new students without improving the learning \
experience for the existing ones. It feels like we're being neglected."
			  << std::endl;
}

void Harl::error(void)
{
	std::cout << "== ERROR ==" << std::endl;
	std::cout << "This is absolutely outrageous! The quality of education at \
42 is severely lacking. I demand to speak to the higher authorities \
immediately. This cannot go on any longer!"
			  << std::endl;
}

void Harl::filter(std::string level)
{
	int i = 0;
	while (i < 4 && level != level_strs[i])
		i++;
	switch (i)
	{
	case DEBUG:
		debug();
		info();
		warning();
		error();
		break;
	case INFO:
		info();
		warning();
		error();
		break;
	case WARN:
		warning();
		error();
		break;
	case ERROR:
		error();
		break;
	default:
		std::cout << "BAD INPUT" << std::endl;
	}
}

std::string Harl::get_type(int level)
{
	return this->level_strs[level];
}
