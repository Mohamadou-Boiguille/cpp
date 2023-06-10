#include "../inc/harl.hpp"

Harl::Harl()
{
    msg[DEBUG] = "I can't believe I have to spend countless hours deciphering \
    cryptic coding puzzles at 42. It's like solving a never-ending maze \
    without any clear direction. Frustrating, isn't it?";
    msg[INFO] = "I'm extremely disappointed with the lack of resources \
    provided by 42. It's like they expect us to magically acquire knowledge \
    without proper guidance. How can they expect us to succeed?";
    msg[WARN] = "I've been at 42 for a while now, and I think it's unfair \
    that they keep accepting new students without improving the learning \
    experience for the existing ones. It feels like we're being neglected.";
    msg[ERROR] = "This is absolutely outrageous! The quality of education at \
    42 is severely lacking. I demand to speak to the higher authorities \
    immediately. This cannot go on any longer!";
    msg[BAD_INPUT] = "I think it's important to remind my fellow student \
    at 42 that using incorrect inputs in programs will lead to \
    unreliable results.";
}

void Harl::complain(std::string level)
{
    size_t msg_index;
    if (level == DEBUG_STR)
        msg_index = DEBUG;
    else if (level == INFO_STR)
        msg_index = INFO;
    else if (level == WARN_STR)
        msg_index = WARN;
    else if (level == ERROR_STR)
        msg_index = ERROR;
    else
    {
        std::cout << msg[BAD_INPUT] << std::endl;
        return;
    }
    std::cout << msg[msg_index] << std::endl;
}
