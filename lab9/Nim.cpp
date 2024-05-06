/* File:    Nim.cpp
 * Course:  CS215-401
 * Project: Lab9
 * Purpose: Defines the Nim class for implementing a game of Nim.
 * Author:  Ian Thornsburg
 */

#include "Nim.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace::std;

// Default Constructor
Nim::Nim()
{
    srand(time(0));
    marble_count = PILE_MAX;
}

// Alternate Constructor
Nim::Nim(int ini_size)
{
    srand(time(0));
    marble_count = ini_size;
}

// Set Function
void Nim::set_marble_count(int size)
{
    marble_count = size;
}

// Accessor for marble_count variable
int Nim::get_marble_count() const
{
    return marble_count;
}

// Prints MARLBE characters for each marble in count
void Nim::print() const
{
    for (int i = 0; i < marble_count; i++)
    {
        cout << MARBLE << " ";
    }
    cout << endl;
}

/*
* Represents a legal move when it is the computer's turn to play
* The computer's move is either a smart-move or
* non-smart-move, depending on the parameter named smart.
* (Note that the private data member, pileSize, will be modified)
*@param smart bool: representing the computer takes smart move (if true)
* or non-smart move (if false)
*@return: void function
*/

void Nim::computer_move(bool smart)
{
    // Variable for findng the amount computer removed
    int oldcount = marble_count;
    if (smart)
    {
        // Silly bit and operator to check if count is a power of 2 - 1
        // If the count was 15 it would & 01000 and 00111 to get 0
        if (((marble_count+1) & marble_count) == 0)
        {
            // Random in range
            marble_count = marble_count - (rand() % (marble_count/2) + 1);
        }
        else
        {
            // Thought about implementing some bit trick to just find leftmost 1 in binary to find the closest power
            // But I thought it'd make more sense to just use a loop in this context
            int closestpower = 0;
            for (int i = 2; i <= marble_count; i = i * 2)
            {
                closestpower = i;
            }
            marble_count = closestpower - 1;
        }

    }
    else
    {
        marble_count = marble_count - (rand() % (marble_count/2) + 1);
    }
    // Print amount removed
    cout << "The computer removed " << oldcount - marble_count << " marbles from the pile." << endl << endl;
}