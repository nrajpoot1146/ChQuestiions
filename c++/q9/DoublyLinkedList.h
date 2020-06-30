#include "Node.h"
#include <string.h>
#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

class DoublyLinkedList{
	private:
		Node *head;
		Node *tail;
	
	public:
		DoublyLinkedList(){
			head = NULL;
			tail = NULL;
		}
		~DoublyLinkedList();
		int IsEmpty(){
			return head == NULL;
		}
		void AddToHead(int data);
		void AddToTail(int data);
		void InsertAfterNthNode(int n, int data);
		void InsertAfterNode(Node* node, int data);
		void DeleteHead();
		void DeleteTail();
		void DeleteNthNode(int n);
		void DeleteNode(Node* node);
		Node* GetHead();
		Node* GetTail();
		Node* GetNthNode(int n);
		
};

#endif
