/*
Course: CS215-401
Project: Lab 2
Purpose: This program prints change in standard american coin units
Author: Ian Thornsburg
*/

#include <iomanip>
#include <iostream>

using namespace std;
int main()
{
        // Collect amounts received and due
    float due = 0.00;
    float received = 0.00;
    cout << "Enter the amount due : $ ";
    cin >> due;
    cout << "Enter the amount received : $ ";
    cin >> received;
        // Do math to find dollars
        // Add .005 to account for rounding error
    float change = received - due + .005;
    int dollars = change / 1;
    change = change - dollars;
        // Do math to find quarters
    const float quarter = .25;
    int quarters = change / quarter;
    change = change - quarters * quarter;
        // Do math to find dimes
    const float dime = .1;
    int dimes = change / dime;
    change = change - dimes * dime;
        // Do math to find nickels
    const float nickel = .05;
    int nickels = change / nickel;
    change = change - nickels * nickel;
        // Do math to find pennies
    const float penny = .01;
    int pennies = change / penny;
    change = change - pennies * penny;
        // Print values
    cout << "The change is:" << endl;
    cout << "Dollars:\t\t" << setw(6) << dollars << endl;
    cout << "Quarters:\t\t" << setw(6) << quarters << endl;
    cout << "Dimes:\t\t\t" << setw(6) << dimes << endl;
    cout << "Nickels:\t\t" << setw(6) << nickels << endl;
    cout << "Pennies:\t\t" << setw(6) << pennies << endl;
}