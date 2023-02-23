// towers-of-hanoi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Utility.h"
#include "Board.h"
#include "Disk.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::stoi;


bool checkUserSelection(Utility* _util, string _choice, bool& _keep_running, bool& _restart)
{
    if ((_choice == "x") || (_choice == "X"))
    {
        _keep_running = false;
        cout << "You have quit the game." << endl;// info msg
    }
    else if ((_choice == "n") || (_choice == "N"))
    {
        _restart = true;
        cout << "Restarting game..." << endl;// info msg
    }
    else if (( _util->isNumber(_choice)) && (stoi(_choice) > 0) && (stoi(_choice) <= 3))
    {
        _util->~Utility();
        return true;
    }
    else
    {
        cout << "You have entered invalid input. Please try again." << endl;// error msg
    }
    return false;
}


int main()
{
    // init vars
    bool keep_running = true;
    bool restart = false;
    bool gameState;
    int noOfMoves = 0;
    string choiceFrom = "";
    string choiceTo = "";
    Board* board = new Board();
    Utility* util = new Utility();

    while (keep_running)// GameLoop
    {
        board->Draw();// draw game board with current data
        
        // continue playing until a win is detected
        cout << "Number of Moves: " << noOfMoves << "\n\n" << endl;
        if (!board->WinGame())
        {
            cout << "Choose Source Tower ([X] to Quit, [N] for New): ";
            cin >> choiceFrom;
            gameState = checkUserSelection(util, choiceFrom, keep_running, restart);
            if (gameState)
            {
                std::cout << "Choose Destination Tower ([X] to Quit, [N] for New): ";
                cin >> choiceTo;
                gameState = checkUserSelection(util, choiceTo, keep_running, restart);
                if (gameState)
                {
                    if (board->MoveDisk((stoi(choiceFrom)), (stoi(choiceTo))))
                    {
                        cout << "Success!" << endl;
                        noOfMoves++;
                    }
                }
            }
        }
        else {
            cout << "\tYOU WIN!!! Good job!\n" << endl;
            cout << "\tRestarting game..." << endl;
            restart = true;
        }

        // housekeeping
        if (!keep_running || restart)
        {
            board->~Board();
            
            if (restart)
            {
                noOfMoves = 0;
                board = new Board();
            }
            else {
                delete(util);
            }
        }

        system("pause");
        Utility::clrscr();
    }

    cout << "\nThankyou for playing, Goodbye!\n" << endl;

}
