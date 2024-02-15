/*
Course: CS215-401
Project: Lab 1
Purpose: This program prints a handsome smiley face using cout, then calculates seconds per week from hours per week.
Author: Ian Thornsburg
*/

#include <iostream>

using namespace std;
int main()
{
    cout << "Hi, Mr. Davis!\nMy name is Ian Thornsburg. Nice to meet you!" << endl;
cout << " -------         -------" << endl;
cout << " | |0| |         | |0| |" << endl;
cout << " | |0| |         | |0| |" << endl;
cout << " | |0| |         | |0| |" << endl;
cout << " -------         -------" << endl;
cout << " " << endl;
cout << " " << endl;
cout << " ----------------------" << endl;
cout << " \\  |8|  |88888| |8|  /" << endl;
cout << "  \\ ---  |88888| --- / " << endl;
cout << "   \\ _   |88888|  _ /" << endl;
cout << "    \\8|   -----  |8/" << endl;
cout << "     \\/          \\/" << endl;
cout << "      \\   _____  / " << endl;
cout << "       \\_|88888|/ " << endl;

//collect user input and calculate the time spent
double hours = 0.0; // declare a variable to store how many hours
cout << "How many hours are you going to spend on CS215 every week?" << endl;
cin >> hours;
const int HOUR_TO_MIN = 60; //declare a constant: 1 hour = 60 minutes
const int MIN_TO_SEC = 60; //declare a constant: 1 minute = 60 seconds
double seconds = hours * HOUR_TO_MIN * MIN_TO_SEC;
cout << "Good Luck! You will spend " << seconds << "seconds each week on CS215." << endl;
return 0;
} 