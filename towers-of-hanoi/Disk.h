#pragma once

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::stoi;

class Disk
{
//private:
	int m_size;

public:
	Disk(int);
	int getSize();
	void Draw();
};

