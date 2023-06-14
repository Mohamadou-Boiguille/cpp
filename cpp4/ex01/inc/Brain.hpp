#pragma once

#ifndef BRAIN_HPP
#include <iostream>

class Brain {
public:
    Brain();
    Brain(const Brain &);
    Brain &operator=(const Brain &);
    ~Brain();
    std::string get_string(unsigned int index);

private:
    
};
#endif // !BRAIN_HPP
