#pragma once

#include <iostream>
#include <string>
#include <array>
#include "Disk.h"
#include "Tower.h"

using std::string;
using std::cout;
using std::endl;
using std::array;

class Board
{
	//private:
	Disk* diskS = new Disk(4);
	Disk* diskM = new Disk(8);
	Disk* diskL = new Disk(12);
	Tower* tower1 = nullptr;
	Tower* tower2 = nullptr;
	Tower* tower3 = nullptr;
	array<Tower*, 3> towerArray = { tower1, tower2, tower3 };

	Tower* assignTower(int);

public:
	Board();
	~Board();
	bool MoveDisk(int, int);
	void Draw();
	bool WinGame();

};
