#pragma once

#include <iostream>
#include <string>

using std::string;
using std::cout;

class Utility
{
//private:
	char* ptr;

public:
	Utility();
	~Utility();
	bool isNumber(string);
	static void clrscr();
};

