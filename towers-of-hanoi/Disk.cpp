#include "Disk.h"

Disk::Disk(int _size)
{
	m_size = _size;
}

int Disk::getSize()
{
	return m_size;
}

void Disk::Draw()
{
	//int size = stoi(m_size);
	int spaces = (12 - m_size) / 2;

	for (int i = 0; i < spaces; i++)
	{
		cout << " ";
	}
	for (int i = 0; i < m_size; i++)
	{
		cout << "*";
	}
	for (int i = 0; i < spaces; i++)
	{
		cout << " ";
	}
	cout << endl;
}
