/*
	Course: CS215-401
	Project: Lab 6
	Purpose: Displays all super bowl numbers 2000-2099
	Author: Ian Thornsburg
	Note: This program uses code written by the instructor, Jeremiah Davis.
*/
#include <iostream>
#include <iomanip>

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
	const int FIRST_YEAR = 1967;

	cout << setw(42) << "Super Bowl Records" << endl;
	cout << "The first Super Bowl was held at the Los Angeles Memorial" << endl;
	cout << "Coliseum on January 15, 1967." << endl;

	cout << setw(12) << "Year" << setw(22) << "Super Bowl" << endl;

	for (int year = 2000; year < 2100; year++)
	{
		int super_bowl_num = year - FIRST_YEAR + 1;
		if (year % 10 == 0)
		{
			cout << endl << "************************************"
				 << endl << endl;
		}
		cout << setw(12) << year << setw(8) << "--->" << "    "
			 << roman_numeral(super_bowl_num) << endl;;
	}

	return 0;
}