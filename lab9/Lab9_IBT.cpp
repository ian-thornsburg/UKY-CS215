/*
 * Course:  CS215-401
 * Project: Lab 9
 * File:    Lab9.cpp
 * Purpose: The Lab 9 driver file.
 * Author:  Jeremiah S. Davis
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Nim.h"

using namespace std;

const string PLAYER_ONE = "DAVIS81";
const string PLAYER_TWO = "HAL9000";

int main()
{
    const int INIT_SIZE = PILE_SIZE_TEST;
    cout << "*****************************************************" << endl;
    cout << "*                  The game of Nim                  *" << endl;
    cout << "*   I will show (not formally prove) that the game  *" << endl;
    cout << "*   of Nim is a ``first-player-win'' game.          *" << endl;
    cout << "*   Two computer players will alternate taking at   *" << endl;
    cout << "*   least one but at most half the marble from the  *" << endl;
    cout << "*   pile. The computer player that takes the last   *" << endl;
    cout << "*   marble loses.                                   *" << endl;
    cout << "*****************************************************" << endl;
    cout << PLAYER_ONE << " and " << PLAYER_TWO << " are two computers." << endl;
    cout << "They play the game of Nim." << endl << endl;
    cout << PLAYER_ONE << " always starts first! " << PLAYER_TWO << " plays second." << endl;
    cout << "Both " << PLAYER_ONE << " and " << PLAYER_TWO << " play under \"smart-move\" mode." << endl << endl;

    Nim game(INIT_SIZE);

    bool player_ones_turn = true;
    bool smart_move = true;

    while (game.get_marble_count() > 1)
    {
        cout << "There are " << game.get_marble_count() << " marbles in the pile." << endl;
        game.print();
        cout << "It is ";
        if (player_ones_turn)
        {
            cout << PLAYER_ONE << "'s turn." << endl;
        }
        else
        {
            cout << PLAYER_TWO << "'s turn." << endl;
        }
        cout << "The computer plays..." << endl;
        game.computer_move(smart_move);
        if (player_ones_turn)
        {
            player_ones_turn = false;
        }
        else
        {
            player_ones_turn = true;
        }
    }

    string loser;
    string winner;

    if (player_ones_turn)
    {
        loser = PLAYER_ONE;
        winner = PLAYER_TWO;
    }
    else
    {
        loser = PLAYER_TWO;
        winner = PLAYER_ONE;
    }
    cout << "Computer " << loser << " must take the last marble. ";
    cout << "Computer " << winner << " wins!" << endl;
    return 0;
}
