#include "Board.h"

Board::Board()
{
	tower1 = new Tower(0);
	tower2 = new Tower(0);
	tower3 = new Tower(0);

	tower1->PushDisk(diskL);
	tower1->PushDisk(diskM);
	tower1->PushDisk(diskS);

	//cout << tower1->DiskCount() << endl;
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
		else if (assignTower(_from)->TopDiskSize() == assignTower(_to)->TopDiskSize())
		{
			cout << "The same tower cannot be used as both source and destination. Please try again." << endl;// error msg

		}
		else {
			cout << "Larger discs cannot be placed on top of smaller ones. Please try again." << endl;// error msg
		}
	}
	else {
		cout << "Cannot use an empty tower as a source. Please try again." << endl;// error msg
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

// draw game screen
void Board::Draw()
{
	string buildString;
	cout << "TOWERS OF HANOI\n\n\n\n\n" << endl;
	for (int i = 2; i >= 0; i--)
	{
		buildString = "";
		buildString += "\t\t\t";
		buildString += tower1->Draw(i);
		buildString += "\t\t\t";
		buildString += tower2->Draw(i);
		buildString += "\t\t\t";
		buildString += tower3->Draw(i);

		cout << buildString << endl;
	}
	cout << "\t\t\t      1\t\t\t\t      2\t\t\t\t      3" << endl;
}

bool Board::WinGame()
{
	if (tower3->DiskCount() == 3)
	{
		return true;
	}
	return false;
}
