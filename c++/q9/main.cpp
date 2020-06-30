//Main.ccp
#include <bits/stdc++.h>

#include <iostream>

#include "DoublyLinkedList.cpp"

using namespace std;

/* Test to verify a new list is empty
 */
void VerifyNewListIsEmpty() {
  DoublyLinkedList list;

  string outCome = list.IsEmpty() ? "Passed" : "Fail";

  cout << "VerifyNewListIsEmpty: " << outCome << endl;
}

/* Test to verify when adding a node to an empty list
the node the head and only node in list
*/
void VerifyEmptyListAddToHead() {
  DoublyLinkedList list;

  // Insert node at front (head)
  list.AddToHead(10);

  Node * head = list.GetHead();
  Node * tail = list.GetTail();

  //Checks if head data is 10 and if its the only item in list
  string outCome = (head != NULL &&
    ( * head).data == 10 &&
    ( * head).next == NULL &&
    head == tail) ? "Passed" : "Fail";

  cout << "VerifyEmptyListAddToHead: " << outCome << endl;
}

/* Test to verify when adding a node to the head on a list
the node the head and the next points to the old head
*/
void VerifyListAddToHead() {
  DoublyLinkedList list;

  // Insert node at front (head)
  list.AddToHead(10);

  Node * firstHead = list.GetHead();

  list.AddToHead(20);

  Node * head = list.GetHead();
  Node * tail = list.GetTail();

  //Checks if head data is 10 and if its the only item in list
  string outCome = (( * head).data == 20 &&
    ( * head).next == firstHead &&
    head != tail &&
    head -> next -> prev == head) ? "Passed" : "Fail";

  cout << "VerifyListAddToHead: " << outCome << endl;
}

/* Test to verify when adding a node to the tail of an empty list
the node is the tail and its the only item in list
*/
void VerifyEmptyListAddToTail() {
  DoublyLinkedList list;

  list.AddToTail(10);

  Node * head = list.GetHead();
  Node * tail = list.GetTail();

  //Checks if tail data is 10 and if its the only item in list
  string outCome = (tail != NULL &&
    ( * tail).data == 10 &&
    ( * tail).next == NULL &&
    head == tail) ? "Passed" : "Fail";

  cout << "VerifyEmptyListAddToTail: " << outCome << endl;
}

/* Test to verify when adding a node to the tail of a list
the node is the tail and its prev node is the last tail
*/
void VerifyAddToTail() {
  DoublyLinkedList list;

  list.AddToHead(20);

  Node * firstTail = list.GetTail();

  list.AddToTail(10);

  Node * tail = list.GetTail();

  //Checks if tail data is 10 and if its the only item in list
  string outCome = (tail != NULL &&
    ( * tail).data == 10 &&
    ( * tail).next == NULL &&
    ( * tail).prev == firstTail &&
    firstTail != tail) ? "Passed" : "Fail";

  cout << "VerifyAddToTail: " << outCome << endl;
}

/* Test to verify when adding a node to the tail of a list
the node is the tail and its prev node is the last tail
*/
void VerifyInsertAfter() {
  DoublyLinkedList list;

  list.AddToHead(10);
  list.AddToTail(20);

  Node * head = list.GetHead();

  list.InsertAfterNode(head, 30); // Insert after head

  Node * nthNode = list.GetNthNode(2);

  // Checks if nthNode data is 30 and if its the only item in list
  string outCome = (nthNode != NULL &&
    ( * nthNode).data == 30 &&
    ( * nthNode).next == list.GetTail() &&
    ( * nthNode).prev == list.GetHead()) ? "Passed" : "Fail";

  cout << "VerifyInsertAfter: " << outCome << endl;
}

/* Test to verify when deleting head
the new head should be the 2nd node
*/
void VerifyDeleteHead() {
  DoublyLinkedList list;

  list.AddToHead(10);
  list.AddToTail(20);
  list.AddToTail(30);

  list.DeleteHead();

  Node * head = list.GetHead();

  // Checks if nthNode data is 30 and if its the only item in list
  string outCome = (head != NULL &&
    ( * head).data == 20 &&
    ( * head).next == list.GetTail() &&
    ( * head).prev == NULL) ? "Passed" : "Fail";

  cout << "VerifyDeleteHead: " << outCome << endl;
}

/* Test to verify when deleting tail
the new tail should be the 2nd to last node
*/
void VerifyDeleteTail() {
  DoublyLinkedList list;

  list.AddToHead(10);
  list.AddToTail(20);
  list.AddToTail(30);

  list.DeleteTail();

  Node * tail = list.GetTail();

  // Checks if nthNode data is 30 and if its the only item in list
  string outCome = (( * tail).data == 20 &&
    ( * tail).prev == list.GetHead() &&
    ( * tail).next == NULL) ? "Passed" : "Fail";

  cout << "VerifyDeleteTail: " << outCome << endl;
}

int main() {
  // Do not modify these test.
  VerifyNewListIsEmpty();
  VerifyEmptyListAddToHead();
  VerifyListAddToHead();
  VerifyEmptyListAddToTail();
  VerifyAddToTail();
  VerifyInsertAfter();
  VerifyDeleteHead();
  VerifyDeleteTail();

  // Extra Credit: Add additional tests here (e.g. Verify Insert after Nth node, Verify Delete Nth Node, Verify Empty List Delete )
}
