
#include<iostream>
#include "LinkedListSingle.cpp"
using namespace std;

int n; // Initializing variables
int s;
int fl;

int main()
{
    cout << "Enter the amount of numbers to be in the list" << endl; // prompt the user to enter the amount of numbers n Ex:3,4,5 and so forth
    cin >> n;

    LinkedListSingle Program4;
    cout << "Random numbers to be displayed forward on the list are" << endl; // Enter postive numbers, which will be displayed forward on the list
    for (int i = 0; i < n; i++)
    {
        Program4.buildListForward(fl);
    }
    cout << endl;
    Program4.PrintListForward(); // print the values
    cout << endl;

    cout << "The sorted list becomes: " << endl;
    Program4.SortLinkedList();   // sort the list
    Program4.PrintListForward(); // print the sorted list
    cout << endl;

    cout << endl
         << "enter a value to search in linked list " << endl;
    cin >> s;
    if (Program4.binarySearch(s) == NULL)
    {
        cout << "searchedItem was not found";
    }
    else
    {
        cout << "searchedItem is found at location: " << Program4.location(s) << endl;
    }
}
