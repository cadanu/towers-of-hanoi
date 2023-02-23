#include "Board.h"

Board::Board()
{
	tower1 = new Tower(0);
	tower2 = new Tower(0);
	tower3 = new Tower(0);

	tower1->PushDisk(diskL);
	tower1->PushDisk(diskM);
	tower1->PushDisk(diskS);
}

Board::~Board()
{
	tower1->~Tower();
	tower2->~Tower();
	tower3->~Tower();
	delete(diskS);
	delete(diskM);
	delete(diskL);	
}

// move disk
bool Board::MoveDisk(int _from, int _to)
{
	// if from tower is not empty
	if (assignTower(_from)->DiskCount() > 0)
	{
		// if to tower is empty, or the 'from' top disk is smaller that the 'to' top disk
		if ((assignTower(_to)->DiskCount() == 0) || (assignTower(_from)->TopDiskSize() < assignTower(_to)->TopDiskSize()))
		{
			assignTower(_to)->PushDisk(assignTower(_from)->PopDisk());
			return true;
		}
		else {
			cout << "Larger discs cannot be placed on top of smaller ones. Please try again." << endl;
		}
	}
	else {
		cout << "Cannot use empty tower as source. Please try again." << endl;
	}
	return false;
}

// assign a tower object based on number selection
Tower* Board::assignTower(int _select)
{
	if (_select == 1)
	{
		return tower1;
	}
	else if (_select == 2)
	{
		return tower2;
	}
	else {
		return tower3;
	}
}



void Board::Draw()
{
	cout << "Drawing board...\n" << endl;	
}

bool Board::WinGame()
{
	bool won = false;
	return won;
}
