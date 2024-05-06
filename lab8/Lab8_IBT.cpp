/* File:    Lab8_IBT.cpp
 * Course:  CS215-401
 * Project: Lab 8
 * Purpose: Creates and manipulates two "Clock" objects.
 * Author:  Ian Thornsburg
 * Note: This program uses code written by the instructor, Jeremiah Davis.
 */

#include <iostream>
#include "Clock.h"

using namespace::std;

int main()
{
// Create C1 Clock object and set its time twice
Clock C1;
C1.setClock(3, -5, 16);
C1.setClock(0, 0, 5);
// Create C2 Clock object
Clock C2(12, 35, 59);

// Print C1
cout << "Clock C1 -- ";
C1.printTime(); 
cout << endl;

// Print C2
cout << "Clock C2 -- ";
C2.printTime(); 
cout << endl;

// Compare C1 with C2.
if (C1.compareTime(C2) < 0)
{
cout << "C1 is earlier than C2" << endl;
}
else if (C1.compareTime(C2) > 0)
{
cout << "C1 is later than C2" << endl;
}
else
{
cout << "C1 is the same as C2" << endl;
}

// Add C2 to C1
C1.addTime(C2);

// Print C1
cout << "Clock C1 -- ";
C1.printTime(); 
cout << endl;

// Print C2
cout << "Clock C2 -- ";
C2.printTime(); 
cout << endl;

// Compare C1 with C2 again.
if (C1.compareTime(C2) < 0)
{
cout << "C1 is earlier than C2" << endl;
}
else if (C1.compareTime(C2) > 0)
{
cout << "C1 is later than C2" << endl;
}
else
{
cout << "C1 is the same as C2" << endl;
}

// Increment C1 by 55 seconds
C1.incrementSeconds(55);

// Print C1
cout << "Clock C1 -- ";
C1.printTime(); 
cout << endl;

// Increment C1 by 119 minutes
C1.incrementMinutes(119);

// Print C1
cout << "Clock C1 -- ";
C1.printTime(); 
cout << endl;

// Increment C1 by 22 hours
C1.incrementHours(22);

// Print C1
cout << "Clock C1 -- ";
C1.printTime(); 
cout << endl;

// Print C2
cout << "Clock C2 -- ";
C2.printTime(); 
cout << endl;

// Compare C2 with C1.
if (C2.compareTime(C1) < 0)
cout << "C2 is earlier than C1" << endl;
else if (C2.compareTime(C1) > 0)
cout << "C2 is later than C1" << endl;
else
cout << "C2 is the same as C1" << endl;
return 0;
}
