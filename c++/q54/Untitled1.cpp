#include <iostream>

using namespace std;

class node{
public:
    int item;
    node *next;

    node(int x, node *t){
        item = x;
        next = t;
    }
};

typedef node *link;
link headNode, currentNode;
void remove();
void insert(int i);
void next(int skips);
int item();

int main() //Creates a circular linked list and cycles through it in specific ways until it makes a node point to itself
{
    int nArray[] = {1000, 100000, 1000000, 10000000}; //Controls size of linked list
    int mArray[] = {2, 3, 5, 10}; //Controls number of values skipped per "deletion"
    int i, N, M;
    cout << "Results From Original Code:" << endl;
    //Insert the Outer-loop that cycles through all 'N' values
    {
        //Inner-loop that cycles through all 'M' values
    }
    M = mArray[k];
    link t = new node(1, t);
    //Creates a new node, storing 1 and points to itself; serves way to close circle
    link x = t;
    //Points to existing node t, serving as first value in list
    //Creates a circular linked list of nodes of 'N' size
    {
        x->next = new node(i, t);
        x = x->next;
    }
    while (x != x->next) //Loops until node points to itself
    {
        //insert for loop
        //Moves forward "M - 1" in the list
        //Changes pointer to the node after the next; practically removes next node
    }
    cout << "While N = " << N << " and M = " << M << ", the result is " << x->item << "." << endl;


    cout << "\nResults From Altered Code (using new functions):" << endl;

    for (int j = 0; j < 4; j++) //Outer-loop that cycles through all 'N' values
    {
        N = nArray[j];
        for (int k = 0; k < 4; k++) //Inner-loop that cycles through all 'M' values
        {
            M = mArray[k];
            headNode = new node(1, headNode); //Creates start of linked list
            currentNode = headNode; //Node points to same memory location as start of list
            for (i = 2; i <= N; i++) //Loops 'N' times, starting from 2
            {
                insert(i); //Adds new node containing 'i' to list
            }
            while (currentNode != currentNode->next) //Loops until 'x' matches what it's pointing to
            {
                next(M - 1); //Skips ahead "M - 1" spaces in completed circular linked list
                remove(); //Removes following value from linked list
            }
            cout << "While N = " << N << " and M = " << M << ", the result is " << item() << "." << endl;
        }
    }
}

void remove() //Postcondition: Removes the node after currentNode from the linked list
{
    currentNode->next = currentNode->next->next;
}

void insert(int i) //Postcondition: Adds a new node to the end of the linked list containing the passed int
{
    currentNode->next = new node(i, headNode);
    next(1);
}

void next(int skips) //Postcondition: Moves forward "skips" places in the linked list
{
    for (int i = 0; i < skips; i++)
    {
        currentNode = currentNode->next;
    }
}

int item() //Postcondition: Returns
{
    return currentNode->item;
}
