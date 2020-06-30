#include <iostream>
#include "BinaryTree.h"

int main(){
	BinaryTree<int> *binaryTree = new BinaryTree<int>();
	binaryTree->insert(1); // insert 1 to binary tree
	binaryTree->insert(45); // insert 45 to binary tree
	binaryTree->insert(20); // insert 20 to binary tree
	binaryTree->insert(50); //insert 50 to binary tree
	std::cout<<"Number of nodes which have one child: "<<numberOfOnes(binaryTree->getRoot()); // print number of nodes that have single child
}
