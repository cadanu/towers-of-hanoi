#include "Disk.h"

Disk::Disk(int _size)
{
	m_size = _size;
}

int Disk::getSize()
{
	return m_size;
}

string Disk::Draw()
{
	int spaces = (12 - m_size) / 2;
	string spacesStr;
	string diskStr;

	for (int i = 0; i < spaces; i++)
	{
		spacesStr += " ";
	}
	for (int i = 0; i < m_size; i++)
	{
		diskStr += "*";
	}
	return spacesStr + diskStr + spacesStr;
}
