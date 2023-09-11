#include "../inc/PmergeMe.hpp"
#include <cstring>
#include <iostream>
#include <limits>

typedef struct s_manualInput
{
	size_t items;
	int min;
	int max;
	std::string itemsStr;
	std::string minStr;
	std::string maxStr;
	char **nbList;
} t_manualInput;

int createRandomNbList(t_manualInput &mInput)
{
	// std::cout << "nbItems = " << mInput.itemsStr << " - minNb = " << mInput.minStr << " - maxNb = " << mInput.maxStr << std::endl;
	std::srand(static_cast<unsigned>(std::time(NULL)));
	mInput.nbList = new char *[mInput.items + 1];
	if (!mInput.nbList)
		return false;
	mInput.nbList[0] = new char[mInput.maxStr.length() + 1];
	mInput.nbList[1] = new char[mInput.minStr.length() + 1];
	if (!mInput.nbList[0] || !mInput.nbList[1])
		return false;
	strcpy(mInput.nbList[0], mInput.maxStr.c_str());
	strcpy(mInput.nbList[1], mInput.minStr.c_str());
	// std::cout << "0: " << mInput.nbList[0] << std::endl;
	// std::cout << "1: " << mInput.nbList[1] << std::endl;
	for (size_t i = 2; i < mInput.items; ++i)
	{
		char buffer[30];
		int randomNumber = mInput.min + std::rand() % (mInput.max - mInput.min + 1);
		sprintf(buffer, "%d", randomNumber);
		mInput.nbList[i] = new char[strlen(buffer) + 1];
		if (!mInput.nbList[i])
			return false;
		strcpy(mInput.nbList[i], buffer);
		// std::cout << i << ": " << randomNumber << "-" << buffer << "-" << mInput.nbList[i] << std::endl;
	}
	mInput.nbList[mInput.items] = NULL;
	// std::cout << "end func" << std::endl;
	return true;
}

int getManualInput(t_manualInput &mInput)
{
	char *ptrEnd;
	std::cout << "How many numbers do you wan't to sort ? (q to quit)\t";
	if ((!(std::cin >> mInput.itemsStr) && std::cin.eof()) || mInput.itemsStr.at(0) == 'q')
	{
		std::cerr << "Exit program." << std::endl;
		return 2;
	}
	if (!(std::cin))
	{
		std::cerr << "Error: Input invalid - RESTART." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return -1;
	}
	mInput.items = strtol(mInput.itemsStr.c_str(), &ptrEnd, 10);
	if (*ptrEnd != '\0' || mInput.items < 2)
	{
		std::cerr << "Bad format for numbers quantity, put to 100." << std::endl;
		mInput.items = 100;
	}
	std::cout << "What will be the minimum value ?        (q to quit)\t";
	if ((!(std::cin >> mInput.minStr) && std::cin.eof()) || mInput.minStr.at(0) == 'q')
	{
		std::cerr << "Exit program." << std::endl;
		return 2;
	}
	if (!(std::cin))
	{
		std::cerr << "Error: Input invalid - RESTART." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return -1;
	}
	mInput.min = strtol(mInput.minStr.c_str(), &ptrEnd, 10);
	if (*ptrEnd != '\0')
	{
		std::cerr << "Bad format for minimum numbers value, put to INT_MIN and your value will be on the input." << std::endl;
		mInput.min = INT_MIN;
	}
	std::cout << "What will be the maximum value ?        (q to quit)\t";
	if ((!(std::cin >> mInput.maxStr) && std::cin.eof()) || mInput.maxStr.at(0) == 'q')
	{
		std::cerr << "Exit program." << std::endl;
		return 2;
	}
	if (!(std::cin))
	{
		std::cerr << "Error: Input invalid - RESTART." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return -1;
	}
	mInput.max = strtol(mInput.maxStr.c_str(), &ptrEnd, 10);
	if (*ptrEnd != '\0')
	{
		std::cerr << "Bad format for maximum numbers value, put to INT_MAX and your value will be on the input." << std::endl;
		mInput.max = INT_MIN;
	}
	return (0);
}

int main(int argc, char *argv[])
{
	if (argc < 2 || argc > 3000)
	{
		std::cerr << "Wrong nb of arguments." << std::endl;
		return 1;
	}
	std::string firstArg = argv[1];
	if (!firstArg.compare("defense"))
	{
		while (true)
		{
			std::cout << "==================================================" << std::endl;
			std::cout << "=                  PmergeMe GUI                  =" << std::endl;
			std::cout << "==================================================" << std::endl;
			t_manualInput mInput;
			int manualInputErrorValue = getManualInput(mInput);
			if (manualInputErrorValue < 0)
				continue;
			if (manualInputErrorValue > 0)
				return manualInputErrorValue;
			// std::cout << "STR: nbItems = " << mInput.itemsStr << " - minNb = " << mInput.minStr << " - maxNb = " << mInput.maxStr << std::endl;
			// std::cout << "INT: nbItems = " << mInput.items << " - minNb = " << mInput.min << " - maxNb = " << mInput.max << std::endl;
			if (createRandomNbList(mInput) == false)
			{
				std::cerr << "Error: creating random nb list" << std::endl;
			}
			else
			{
				// for (size_t i = 0; i < mInput.items; i++)
				// 	std::cout << i << ": check array : " << mInput.nbList[i] << std::endl;
				PmergeMe defense(mInput.nbList);
				delete[] mInput.nbList;
			}
			std::cout << "\n\n"
					  << std::endl;
		}
	}
	else
		PmergeMe sort(argv);
	return 0;
}
