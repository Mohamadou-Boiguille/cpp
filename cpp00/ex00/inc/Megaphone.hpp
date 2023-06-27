#pragma once

#include <cstdio>
#include <iostream>
#include <string>

class Megaphone
{
  public:
	Megaphone();
	Megaphone(std::string input);
	bool printUpper(int argc, char **argv);
};
