/*
Course: CS215-401
Project: Lab 4
Purpose: This program analyzes a series of numbers that the user inputs
Author: Ian Thornsburg
*/

#include <iostream>
#include <limits>
#include <cmath>

using namespace std;
bool isprime (int n);
int main()
{
    // Setup variables and prime number function that will later be defined in greater detail
    int input = 0;
    int total = 0;
    int largest = 0;
    int smallest = 0;
    int prime = 0;
    // While loop so program repeats
    while(true)
    {
        cout << "Please enter a series of number, then type Q or q to process: ";;
        cin >> input;
        // If cin succeeds
        if (!cin.fail())
        {
            // Calculate values for output
            total += input;
            if (largest < input || largest == 0)
            {
                largest = input;
            }
            if (input < smallest || smallest == 0)
            {
                smallest = input;
            }
            if (isprime(input))
            {
                prime++;
            }
            cout << "The current cumulative sum is: " << total << endl;
            cin.clear();
            // Pulled from a github I found, discards all values using defined limits until a newline is reached and then discards the newline too, completely clearing the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        while (cin.fail())
        {
            cin.clear();
            string input_to_check;
            cin >> input_to_check;
            //Check for q character
            if (input_to_check == "q" || input_to_check == "Q")
            {
                //Check for no inputs
                if(total == 0)
                    {
                        cout << "No input number!" << endl;
                        cout << "Have a great day!" << endl;
                        return 0;
                    }
                    else
                    {
                        //Print end statements
                        cout << "Largest: " << largest << endl;
                        cout << "Smallest: " << smallest << endl;
                        cout << "How many Prime numbers? " << prime << endl;
                        return 0;
                    }
            }
            else
            {
                //Invalid if not q
                cout << "Invalid input, please try again... " << endl;
                break;
            }
        }
    }
}

bool isprime(int n)
{
    //Check if number is not prime by checking if it is less than or equal to 1
    if (n <= 1)
    {
        return false;
    }
    //IDK if there's a more optimal solution for this, but observably its fairly quick up until the integer limit.
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        //Check if number divides without remainder
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}