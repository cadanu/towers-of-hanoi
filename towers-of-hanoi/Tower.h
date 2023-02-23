#pragma once

#include "Disk.h"
#include <vector>

using std::vector;

class Tower
{
//private:
	int m_noOfDisks;
	vector<Disk*> stack;

public:
	Tower(int);
	~Tower();
	Disk* PopDisk();
	void PushDisk(Disk*);
	string Draw(int);
	int DiskCount();
	int TopDiskSize();
};

