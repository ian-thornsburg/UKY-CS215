/*
 * Course:  CS215-401
 * Project: Project 2
 * File:    Project2_IBT.cpp
 * Purpose: The Project 2 driver file for playing Nim.
 * Author:  Ian B.V Thornsburg
 */
#include <iostream>
#include <cstdlib>
#include "Nim.h"
#include <random>

using namespace std;

int main()
{
    cout << "*****************************************************" << endl;
    cout << "*                  The game of Nim                  *" << endl;
    cout << "*   Players alternate taking at least one but at    *" << endl;
    cout << "*   most half of the marbles in the pile.           *" << endl;
    cout << "*   The player who takes the last marble loses.     *" << endl;
    cout << "*   This game was written by Ian Thornsburg.        *" << endl;
    cout << "*   Good luck beating the computer!                 *" << endl;
    cout << "*****************************************************" << endl;
    
    // Create bools for the 2 random variables of who goes first and whether the CPU plays smart
    bool userturn = false;
    bool smart;

    // Call random functions to check who goes first and whether CPU is smart
    if(random(0, 1) == 1)
    {
        userturn = true;
        cout << "You will take the first turn!" << endl;
    }
    else
    {
        cout << "The computer will take the first turn!" << endl;
    }

    if(random(0, 1) == 1)
    {
        smart = true;
        cout << "The computer is going to play smart!" << endl;
    }
    else
    {
        cout << "The computer is NOT going to play smart!" << endl;
    }

    cout << endl;

    // Call game class constructor with random size between min and max
    Nim game(random(PILE_MIN, PILE_MAX));
    while (game.get_marble_count() > 1)
    {
        cout << "There are " << game.get_marble_count() << " marbles in the pile." << endl;
        game.print();
        // Either run player move or computer move depending upon whose turn it is
        if (userturn)
        {
            cout << "Your turn." << endl;
            if(game.player_move())
            {
                userturn = false;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            cout << "The computer plays..." << endl;
            game.computer_move(smart);
            userturn = true;
        }
    }

    // Print win and lose text based on whose turn it is when the game loop ends.
    if (userturn)
    {
        cout << "You must take the last marble. Sorry! You lost." << endl;
    }
    else
    {
        cout << "The computer must take the last marble. Congratulations! You won!" << endl;
    }
    return 0;
}
