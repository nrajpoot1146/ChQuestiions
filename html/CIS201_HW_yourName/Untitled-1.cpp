/* opening comment section
*/
#include <iostream>
#include <fstream>
using namespace std;
struct dogNode
{
    string name;
    string color;
    double weight;
    int age;
    string breed;
    dogNode *next;
};

// function prototypes
dogNode *buildDogList(dogNode *);

int main()
{
    dogNode *head = NULL;
    head = buildDogList(head);
    /* add your function calls here */

    return 0;
}
dogNode *buildDogList(dogNode *firstDog)
{
    ifstream inData;
    dogNode *currentDog, *newDog;

    inData.open("dogs.dat");
    if (!inData)
    {
        cout << "File Open Error" << endl;
        exit;
    }
    while (!inData.eof())
    {
        newDog = new dogNode; // create a new dogNode

        // read in all data for one dog
        inData >> newDog->name;
        inData >> newDog->color;
        inData >> newDog->weight;
        inData >> newDog->age;
        inData >> newDog->breed;
        newDog->next = NULL;
        if (!firstDog)
        {
            firstDog = newDog;
        }
        else
        {
            currentDog = firstDog;
            while (currentDog->next)
            {
                currentDog = currentDog->next;
            }
            currentDog->next = newDog;
        }
    }
    inData.close();
    return firstDog;
}
void printDogList(dogNode *first)
{
    // print the list out --- code here
}

/*
add the other functions here
*/