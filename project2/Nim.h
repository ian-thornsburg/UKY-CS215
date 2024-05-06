/*
 * Course: CS215-401
 * Project: Project 2/Lab 9
 * File: Nim.h
 * Purpose: Declares the Nim class for implementing a game of Nim.
 *
 */

#ifndef NIM_H
#define NIM_H

const int PILE_MAX = 250;
const int PILE_MIN = 10;
const char MARBLE = static_cast<char>(232);  // Use code 232 in ASCII Table to represent marble
const int WIDTH = 10;                        // for layout purposes.
const int PILE_SIZE_TEST = 50;               // The pile size for testing purposes in Lab 9 only.

// Non-member function added for the random function.
int random(int min, int max);

class Nim
{
public:
    // Default constructor
    Nim();

    // Alternate constructor
    Nim(int ini_size);

    // Set the current size of the pile.
    void set_marble_count(int size);

    // Get how many marbles are on the pile.
    int get_marble_count() const;

    // If it is computer's turn to play
    // It is either under smart mode or non-smart mode
    void computer_move(bool smart);

    // If it is player's (the user's) turn to play
    // Returns `true` if the player makes a move, removing
    // marbles from the pile.
    // Returns `false` if the player forfeits.
    bool player_move();

    // Display the current marbles on the pile
    void print() const;

private:
    int marble_count;   // Represents how many marbles are 
                        // on the pile.
};

#endif  /* NIM_H */
