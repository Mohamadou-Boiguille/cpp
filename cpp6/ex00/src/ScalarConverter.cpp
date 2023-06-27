#include "../inc/ScalarConverter.hpp"
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <sstream>
#include <limits>
#include <string>

#define CHAR 1
#define INT 10
#define FLOAT 100
#define DOUBLE 1000

int isRepresentationOf(t_convert *convertSet, std::string str);
ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(std::string str) {
    this->convert(str);
}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {
  *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
  if (this != &other) {
  }
  return *this;
}

ScalarConverter::~ScalarConverter() {
}

void printValue(t_convert *convertSet, int i)
{
    if (i == 0) {
        std::cout << (*convertSet).toChar << std::endl;
    } else if (i == 1) {
        std::cout << (*convertSet).toInt << std::endl;
    } else if (i == 2) {
        std::cout << (*convertSet).toFloat << std::endl;
    } else if (i == 3) {
        std::cout << (*convertSet).toDouble << std::endl;
    }
}

void ScalarConverter::convert(std::string litteral)
{
    t_convert convertSet;
    std::string typeStr[] = {"char", "int", "float", "double"};
    int converted = isRepresentationOf(&convertSet, litteral);

    for (int i = 0; i < 4; i++)
    {
        std::cout << typeStr[i] << ":\t";
        if (converted % 10)
            printValue(&convertSet, i);
        else
            std::cout << "impossible" << std::endl;
        converted /= 10;
    }
}

bool isInt(long double x) {
    return x >= std::numeric_limits<int>::min() 
    && x <= std::numeric_limits<int>::max();
}

int isRepresentationOf(t_convert *set, std::string str)
{
    std::istringstream isstream(str);
    long double doubleNb;
    int intNb;
    set->representation = 0;

    if (isstream >> doubleNb)
    {
        set->representation += DOUBLE;
        set->toDouble = doubleNb;
    }
    else if (isstream >> intNb)
        set->toDouble = intNb;
    else
        return 0;
    if (isInt(set->toDouble))
    {
        set->representation += INT;
        set->toInt = set->toDouble;
    }
    if (set->representation && isascii(set->toInt))
    {
        set->representation += CHAR;
        set->toChar = set->toInt;
    }
    set->representation += FLOAT;
    set->toFloat = static_cast<float>(set->toDouble);
    return set->representation;
}
