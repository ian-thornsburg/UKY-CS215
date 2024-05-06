/*
 * Course:  CS215-401
 * Project: Lab 11
 * File:    Lab11.cpp
 * Purpose: Demonstrate basic competancy with the linked list library.
 * Author:  Ian Thornsburg
 */

#include <iostream>
#include <list>
#include <string>

using namespace std;

// Returning either true or false. Serves to search through a linked list type and find if a specific value is included.
bool list_search(list<string> myList, string item)
{
    auto pos = myList.begin();
    while (pos != myList.end())
    {
    if (*pos == item)
    {
        return true;
    }
    pos++;
    }
    return false;
}

// Void function that prints every value in a linked list type
void print_list(list<string> myList)
{
    auto pos = myList.begin();
    while (pos != myList.end())
    {
    cout << *pos << endl;
    pos++;
    }
}

int main()
{
    list<string> groceries;

    // Add eggs, milk, cabbage, lettuce, flowers to
    // your grocery list using the appropriate list
    // method.

    // Used push_back to add values to end of list
    groceries.push_back("eggs");
    groceries.push_back("milk");
    groceries.push_back("cabbage");
    groceries.push_back("lettuce");
    groceries.push_back("flowers");


    print_list(groceries);

    if (list_search(groceries, "eggs"))
    {
        cout << "There are eggs in the list." << endl;
    }
    else
    {
        cout << "There are no eggs in the list." << endl;
    }

    if (list_search(groceries, "onions"))
    {
        cout << "There are onions in the list." << endl;
    }
    else
    {
        cout << "There are no onions in the list." << endl;
    }

    // Remove eggs from the list using the appropriate list
    // method.

    // Used remove for greater generality and to remove specific values if present
    groceries.remove("eggs");

    print_list(groceries);

    // Add onions and bacon to the list using the appropriate
    // list method. 
    groceries.push_back("onions");
    groceries.push_back("bacon");

    print_list(groceries);

    if (list_search(groceries, "eggs"))
    {
        cout << "There are eggs in the list." << endl;
    }
    else
    {
        cout << "There are no eggs in the list." << endl;
    }

    if (list_search(groceries, "onions"))
    {
        cout << "There are onions in the list." << endl;
    }
    else
    {
        cout << "There are no onions in the list." << endl;
    }

    return 0;
}