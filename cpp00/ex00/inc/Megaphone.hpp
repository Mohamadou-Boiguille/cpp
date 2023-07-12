#pragma once

#include <cstdio>
#include <iostream>
#include <string>

class Megaphone
{
  public:
	Megaphone();
	Megaphone(std::string input);
	void printUpper(int argc, char **argv);
};
