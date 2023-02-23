#pragma once

#include <string>

using std::string;

class Disk
{
//private:
	int m_size;

public:
	Disk(int);
	int getSize();
	string Draw();
};

