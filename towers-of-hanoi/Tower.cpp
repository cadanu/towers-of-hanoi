#include "Tower.h"

Tower::Tower(int _noOfDisks)
{
	m_noOfDisks = _noOfDisks;
}

Tower::~Tower()
{
	stack.clear();
}

Disk* Tower::PopDisk()
{
	Disk* pop = nullptr;

	if (m_noOfDisks > 0)
	{
		pop = stack.front();
		stack.pop_back();
		m_noOfDisks--;
	}
	return pop;// if nullptr then Tower is empty
}

void Tower::PushDisk(Disk* _diskToStack)
{
	if (stack.empty() || (_diskToStack->getSize() < (stack.front()->getSize())))
	{
		stack.push_back(_diskToStack);
		m_noOfDisks++;
	}
}

void Tower::Draw(int position)
{
	if (!stack.empty())
	{
		stack[position]->Draw();// draw disk at vector position
	}
}

int Tower::DiskCount()
{
	return m_noOfDisks;
}

int Tower::TopDiskSize()
{
	if (m_noOfDisks > 0)
	{
		return stack.front()->getSize();
	}
	return 0;
}
