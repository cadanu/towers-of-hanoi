#include "Tower.h"

// constructor
Tower::Tower(int _noOfDisks)
{
	m_noOfDisks = _noOfDisks;
}

// destructor
Tower::~Tower()
{
	stack.clear();
}

// remove disk from tower
Disk* Tower::PopDisk()
{
	Disk* pop = nullptr;

	if (m_noOfDisks > 0)
	{
		pop = stack.back();
		stack.pop_back();
		m_noOfDisks--;
	}
	return pop;// if nullptr then Tower is empty
}

// push disk onto tower
void Tower::PushDisk(Disk* _diskToStack)
{
	if (stack.empty() || (_diskToStack->getSize() < TopDiskSize()))
	{
		stack.push_back(_diskToStack);
		m_noOfDisks++;
	}
}

// draw disk at tower vector position
string Tower::Draw(int _position)
{
	if (!stack.empty() && _position < m_noOfDisks)
	{
		return stack[_position]->Draw();
	}
	return "            ";
}

// count number of disks
int Tower::DiskCount()
{
	return m_noOfDisks;
}

int Tower::TopDiskSize()
{
	// check size of the disk on top
	if (m_noOfDisks > 0)
	{
		return stack.back()->getSize();
	}
	return 0;
}
