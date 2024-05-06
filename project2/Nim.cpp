/* File:    Nim.cpp
 * Course:  CS215-401
 * Project: Project 2
 * Purpose: Defines the Nim class for implementing a game of Nim.
 * Author:  Ian B.V Thornsburg
 */

#include "Nim.h"
#include <iostream>
#include <cstdlib>
#include <random>

using namespace::std;

// Decided to implement the random library, mostly due to the distribution tool. The implementation with modulo gave an uneven distribution.
int random(int min, int max)
{
    int random = 0;
    // Use hardware random number generator (time would be an option but is technically pseudorandom)
    random_device seed;
    // Merlin twist random number generator
    mt19937 generator(seed());
    // Generate a number across a uniform distribution
    uniform_int_distribution<int> distrib(min, max);
    random = distrib(generator);
    // Return generated random number in range
    return random;
}

// Default Constructor
Nim::Nim()
{
    marble_count = PILE_MAX;
}

// Alternate Constructor
Nim::Nim(int ini_size)
{
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

// Prints MARBLE characters for each marble in count
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
            marble_count = marble_count - (random(1, marble_count/2));
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
            marble_count = marble_count - (random(1, marble_count/2));
    }
    // Print amount removed
    cout << "The computer removed " << oldcount - marble_count << " marbles from the pile." << endl << endl;
}

/*
* Represents a legal move when it is the user's turn to play the game
* (it should repeatedly ask the user to enter how many marbles to take
* until the user makes a legal move, or enters “F” or “f” to forfeit.)
* (Note that the private data member, pileSize, will be modified)
*@return: void function
*/

bool Nim::player_move()
{
    int oldcount = marble_count;
    while(true)
    {
        // Get input
        cout << "How many marbles do you want to remove (1-" << marble_count/2 << ")? ";
        int remove = 0;
        cin >> remove;
        int maxremove = marble_count/2;
        // If cin succeeds
        if (!cin.fail())
        {
            // Check to see if entered value is out of range
            if (remove > maxremove || remove < 1)
            {
                cout << "That number of marbles is not between 1 and " << maxremove << " Try again." << endl;
            }
            // if not then perform operation
            else
            {
                marble_count = marble_count - remove;
                cout << "You removed " << oldcount - marble_count << " marbles from the pile." << endl << endl;
                return true;
            }
            
            cin.clear();
            cin.ignore(256, '\n');
        }
        if(cin.fail())
        {
            cin.clear();
            string input_to_check;
            cin >> input_to_check;
            cin.ignore(256, '\n');
            // Check for forfeit character
            if (input_to_check == "f" || input_to_check == "F")
            {
                cout << "You forfeited the game. Sorry! You lost." << endl;
                return false;
            }
            else
            {
                // Invalid if not f
                cout << "Not an integer! Please enter an integer value between 1 and " << maxremove << "." << endl;
            }
        }
    }
}