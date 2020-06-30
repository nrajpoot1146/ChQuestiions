#include<bits/stdc++.h>

#ifndef NODE
#define NODE

struct Node{
	public:
		int  data;
		Node* next;
		Node* prev;
		
		Node(){
			next = NULL;
		}
		
		Node(int d, Node *n = NULL, Node *p = NULL){
			data = d;
			next = n;
			prev = p;
		}
};

#endif
