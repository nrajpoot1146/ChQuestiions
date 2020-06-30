#include<iostream>
//#include

using namespace std;

class LinkedListSingle
{
private:
    typedef struct node
    {
        int data;
        node *next;
    } * nodePtr;

    nodePtr head;
    nodePtr curr;
    nodePtr temp;

public:
    LinkedListSingle();
    void buildListForward(int addData);
    void PrintListForward();
    void SortLinkedList();
    int middle(nodePtr start, nodePtr end);
    int binarySearch(int key);
    int location(int key);
};
