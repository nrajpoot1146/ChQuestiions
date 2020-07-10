
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

/**
* Node structure for binary tree
* contains data field
* left subtree pointer
* right subtree pointer
*/
struct Node{
	int data;
	Node *left;
	Node *right;
	
	/**
	* default constructor to create a node
	*/
	Node(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

/**
* function to calculate max diff. between to node data and its descendants
* print max difference and its descendants 
*/
void maxDiff(Node *root){
	int min,max;
	min = root->data;
	max = root->data;
	stack<Node*> stk; 

	// traverse tree in inorder
	while (root != NULL || stk.empty() == false){
		while (root != NULL){
			stk.push(root);
			root = root->left;
		}
		
		root = stk.top();
		stk.pop();
		
		// condition to find max element
		if (root->data > max){
			max = root->data;
		}
		
		// condition to find min element
		if (root->data < min){
			min = root->data;
		}
		
		root = root->right;
	}
	
	cout<<"The maximum difference between a node and its descendants is "<<max<<" - "<<min<<" = "<<max-min;
}

int main(){
	// create a root node
	Node *root = new Node(6);
	root->left = new Node(3);
	root->right = new Node(8);
	root->right->left = new Node(2);
	root->right->right = new Node(4);
	root->right->left->left = new Node(100);
	root->right->left->right = new Node(7);
	
	maxDiff(root);
}
