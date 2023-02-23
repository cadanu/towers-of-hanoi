#include "Utility.h"

using std::strtol;

Utility::Utility() {}

Utility::~Utility()
{
	*ptr = 0;
}

bool Utility::isNumber(string _strToCheck)
{
	// reference: https://stackoverflow.com/questions/32662034/how-to-use-a-stoi-and-return-false-if-the-string-has-a-letter-in-c
	strtol(_strToCheck.c_str(), &ptr, 10);
	return *ptr == '\0';
}

void Utility::clrscr()
{
	// reference: https://stackoverflow.com/questions/17335816/clear-screen-using-c#32008479
	cout << "\033[2J\033[1;1H";
}
