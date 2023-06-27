#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <algorithm>
# include <cctype>
# include <iostream>
# include <string>

typedef struct s_convert
{
	int		representation;
	int		toInt;
	float	toFloat;
	double	toDouble;
	char	toChar;
	std::string strs[4];
}			t_convert;

class ScalarConverter
{
  public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();
	ScalarConverter(std::string str);
	void convert(std::string litteral);

  private:
};

#endif // !SCALARCONVERTER_HPP
