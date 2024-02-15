/*
Course: CS215-401
Project: Lab 5
Purpose: This program generates triangles given a user input
Author: Ian Thornsburg
*/

#include <iostream>
#include <limits>

// Setup function placeholders
void printTri(int star);
void printTriR90(int star);
void printTriR180(int star);
// Setup max constant
const int maxsize = 30;
using namespace std;

int main()
{
while(true)
    {
        // Get input
        cout << "Enter the size of your triangle (integer in [1, 30])\nType Q to quit the program: ";
        int star = 0;
        cin >> star;
        // If cin succeeds
        if (!cin.fail())
        {
            //if in range print trangles, else print size in wrong range
            if (star >= 1 && star <= maxsize)
            {
            cout << "The triangle with size " << star << "is:" << endl;
            printTri(star);
            cout << "The rotation for 90 degrees clockwise:" << endl;
            printTriR90(star);
            cout << "The rotation for 180 degrees clockwise:" << endl;
            printTriR180(star);
            }
            else
            {
                cout << "The size is not in the correct range!" << endl;
            }
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
                cout << "Thank you, have a great day!" << endl;
                return 0;
            }
            else
            {
                //Invalid if not q
                cout << "The size is not in the correct range!" << endl;
                break;
            }
        }
    }
}

void printTri(int star)
{	
	for (int i = 0; i < star; i++)
	{
		for (int j = 0; j < star - i - 1; j++)
		{
			cout << " ";
		}
		for (int k = 0; k < 2 * i + 1; k++)
		{
			cout << "*";
		}
		cout << endl;
	}
return;
}

void printTriR90(int star)
{
	for (int i = 0; i < star; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (int k = star - 1; k > 0; k--)
	{
		for (int c = 0; c < k; c++)
		{
			cout << "*";
		}
		cout << endl;
	}
    return;
}

void printTriR180(int star)
{
    for (int i = 0; i < star; i++)
	{
		for (int k = 0; k < i; k++)
		{
			cout << " ";
		}
		for (int j = 0; j < 2 * star - 2 * i - 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	return;
}