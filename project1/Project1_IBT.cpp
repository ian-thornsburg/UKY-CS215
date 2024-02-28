/*
	Course: CS215-401
	Project: Lab 6
	Purpose: Asks the user for a year and displays the superbowl for that year using roman numerals 
	Author: Ian Thornsburg
*/

#include <iostream>
#include <limits>

using namespace std;

/*
   It returns a string form of a Roman Numeral.
   n must be between 1 and 3999, inclusive.
   @param n int: representing the number to convert into Roman Numeral
   @return string: representing the corresponding Roman Numeral for n
*/
string roman_numeral(int n)
{
	//Setup constants for numerals
	const int M = 1000;
	const int CM = 900;
	const int D = 500;
	const int CD = 400;
	const int C = 100;
	const int XC = 90;
    const int L = 50;
    const int XL = 40;
    const int X = 10;
    const int IX = 9;
    const int V = 5;
    const int IV = 4;
    const int I = 1;

	//Create two arrays for numbers and characters for roman numerals
	const string roman[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
	const int romanint[] = {I, IV, V, IX, X, XL, L, XC, C, CD, D, CM, M};
	const int arraylen = 13;

	//The arrays allow these two loops to cycle through and output the roman numeral in a relatively neat way.
	int remainder = n;
	string output;

	for (int i = arraylen - 1; i > -1; i--)
	{
		while (remainder >= romanint[i])
		{
    		output = output + roman[i];
    		remainder -= romanint[i];
		}
	}
	return output;
}

int main()
{
    const int firstbowl = 1967;
    string numeral;
    while(true)
        {
            // Setup opening instructions
            cout << endl << "****************************************************************" << endl
            << "* Super Bowl I took place on January 15, 1967.                 *" << endl
            << "* This Roman Numerals Converter was written by Ian Thornsburg. *" << endl
            << "* If you had a time machine, which year of the Super Bowl      *" << endl
            << "* would you like to attend (1967 - 5965) ?                     *" << endl
            << "****************************************************************" << endl << endl
            << "Please enter the year you want to attend (press Q or q to quit) : ";
            int input = 0;
            cin >> input;
            // If cin succeeds
            if (!cin.fail())
            {
                // Check years and either print output if in range or prompt for new input if out of range
                if (input >= 1967 && input <= 5965)
                {
                    // Math must be done to give te roman numeral function the superbowl number instead of the year
                    numeral = roman_numeral(input - firstbowl + 1);
                    cout << "The time machine would bring you to " << input << "." << endl
                    << "You would be attending Super Bowl " << numeral << "!" << endl;
                }
                else if (input < 1967)
                {
                    cout << "Uh oh! This given year was before the first Super Bowl. Try another one!" << endl;
                }
                else
                {
                    cout << "Uh oh! This given year is greater than 5965. Try another one!" << endl;
                }
                // Discards all values using defined limits until a newline is reached and then discards the newline too, completely clearing the input buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                cin.clear();
                string input_to_check;
                cin >> input_to_check;
                //Check for q character
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (input_to_check == "q" || input_to_check == "Q")
                {
                    cout << "Back to 2024. Have a great day!" << endl;
                    return 0;
                }
                else
                {
                    //Invalid if not q
                    cout << "Invalid input, please try again..." << endl;
                    break;
                }
            }
        }
        return 0;
}