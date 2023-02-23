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
        cout << "You have quit the game." << endl;
    }
    else if ((_choice == "n") || (_choice == "N"))
    {
        _restart = true;
        cout << "Game has been reset." << endl;
    }
    else if (( _util->isNumber(_choice)) && (stoi(_choice) > 0) && (stoi(_choice) <= 3))
    {
        _util->~Utility();
        return true;
    }
    else
    {
        cout << "You have entered invalid input. Please try again." << endl;
    }
    return false;
}

int main()
{
    // int vars
    bool keep_running = true;
    bool restart = false;
    bool gameState;
    int noOfMoves = 0;
    string choiceFrom = "";
    string choiceTo = "";
    Board* board = new Board();
    Utility* util = new Utility();

    while (keep_running)
    {
        board->Draw();
        
        std::cout << "Number of Moves: " << noOfMoves << "\n\n" << endl;
        std::cout << "Choose Source Tower ([X] to Quit, [N] for New): ";
        std::cin >> choiceFrom;
        gameState = checkUserSelection(util, choiceFrom, keep_running, restart);
        if (gameState)
        {
            std::cout << "Choose Destination Tower ([X] to Quit, [N] for New): ";
            std::cin >> choiceFrom;
            gameState = checkUserSelection(util, choiceFrom, keep_running, restart);
            if (gameState)
            {
                board->MoveDisk(stoi(choiceFrom), stoi(choiceTo));
                if (true)
                {
                    cout << "Success!" << endl;
                    noOfMoves++;
                }
            }
        }

        if (!keep_running || restart)
        {
            board->~Board();
            
            if (restart)
            {
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




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
