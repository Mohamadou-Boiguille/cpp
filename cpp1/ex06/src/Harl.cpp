#include "../inc/Harl.hpp"

Harl::Harl()
{
	msg[DEBUG] = "- I can't believe I have to spend countless hours deciphering\
    cryptic coding puzzles at 42. It's like solving a never-ending maze\
    without any clear direction. Frustrating, isn't it?\n";
	msg[INFO] = "- I'm extremely disappointed with the lack of resources\
    provided by 42. It's like they expect us to magically acquire knowledge\
    without proper guidance. How can they expect us to succeed?\n";
	msg[WARN] = "- I've been at 42 for a while now, and I think it's unfair\
    that they keep accepting new students without improving the learning\
    experience for the existing ones. It feels like we're being neglected.\n";
	msg[ERROR] = "- This is absolutely outrageous! The quality of education at\
    42 is severely lacking. I demand to speak to the higher authorities\
    immediately. This cannot go on any longer!\n";
	msg[BAD_INPUT] = "- I think it's important to remind my fellow student\
    at 42 that using incorrect inputs in programs will lead to\
    unreliable results.\n";
}

void Harl::complain(std::string level)
{
	size_t	msg_index;

	msg_index = BAD_INPUT;
	if (level == DEBUG_STR)
		msg_index = DEBUG;
	else if (level == INFO_STR)
		msg_index = INFO;
	else if (level == WARN_STR)
		msg_index = WARN;
	else if (level == ERROR_STR)
		msg_index = ERROR;
	switch (msg_index)
	{
	case DEBUG:
		std::cout << msg[0] << msg[1] << msg[2] << msg[3] << "\n";
		break ;
	case INFO:
		std::cout << msg[1] << msg[2] << msg[3] << "\n";
		break ;
	case WARN:
		std::cout << msg[2] << msg[3] << "\n";
		break ;
	case ERROR:
		std::cout << msg[3] << "\n";
		break ;
	default:
		std::cout << msg[msg_index] << "\n";
		break ;
	}
}
