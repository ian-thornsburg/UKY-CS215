/*
Course: CS215-401
Project: Lab 3
Purpose: This program converts a decimal value to a roman numeral value
Author: Ian Thornsburg
*/

#include <iostream>

using namespace std;
int main()
{
cout << "Welcome to CS215 Roman Numeral Converter" << endl <<
"Please input the number you want to convert to Roman numerals" << endl <<
"(at the range of [1, 99]): ";
// Check that number is in range
int decimal = 0;
cin >> decimal;
if (decimal > 99 || decimal < 1)
{
    cout << "Your input number is not in the correct range." << endl;
}
else
{
//Create remainder variable
int remainder = decimal;
//Setup constants
const int XC = 90;
const int L = 50;
const int XL = 40;
const int X = 10;
const int IX = 9;
const int V = 5;
const int IV = 4;
const int I = 1;
//While loops to count down from decimal to find the numeral
while (remainder >= XC)
{
    cout << "XC";
    remainder -= XC;
}
while (remainder >= L)
{
    cout << "L";
    remainder -= L;
}
while (remainder >= XL)
{
    cout << "XL";
    remainder -= XL;
}
while (remainder >= X)
{
    cout << "X";
    remainder -= X;
}
while (remainder >= IX)
{
    cout << "IX";
    remainder -= IX;
}
while (remainder >= V)
{
    cout << "V";
    remainder -= V;
}
while (remainder >= IV)
{
    cout << "IV";
    remainder -= IV;
}
while (remainder >= I)
{
    cout << "I";
    remainder -= I;
}
cout << endl;
}
cout << "Press any key to close this window..." << endl;
}