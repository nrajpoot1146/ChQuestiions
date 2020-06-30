
#ifndef BinaryTree_H
#define BinaryTree_H

#include <iostream>

template <class T>
struct node
{
    T info;
    node<T> *llink;
    node<T> *rlink;
    
    node(T data){
    	this->info = data;
    	this->llink = NULL;
    	this->rlink = NULL;
	}
};

template <class T>
class BinaryTree
{
protected:
    node<T> *root;

private:
    void destroy(node<T> *);
    void inorderD(node<T> *);
    void preorderD(node<T> *);
    void postorderD(node<T> *);
    
    /**
    * function to insert a node to binary tree
    */
    void insert(node<T> *, node<T> *);
    int height(node<T> *);
    int max(int, int);
    int nodecount(node<T> *);
    int leavescount(node<T> *);

public:
	/**
	* insert a node to binary tree
	*/
	void insert(T data){
		node<int> *n = new node<int>(data);
		if ( this->root == NULL ){
			this->root = n;
			return;
		}
		this->insert(this->root, n);
	}
    BinaryTree()
    {
        root = NULL;
    }
    ~BinaryTree()
    {
        destroy(root);
    }
    bool isEmpty()
    {
        return root == NULL;
    }
    void inorder()
    {
        inorderD(root);
    }
    void preorder()
    {
        preorderD(root);
    }
    void postorder()
    {
        postorderD(root);
    }
    int treeheight()
    {
        return height(root);
    }
    int lcount()
    {
        return leavescount(root);
    }
    node<T> *getRoot(){
    	return this->root;
	}
};

template <class T>
void BinaryTree<T>::inorderD(node<T> *p)
{
    if (p != NULL)
    {
        inorderD(p->llink);
        std::cout << p->info << " ";
        inorderD(p->rlink);
    }
}

template <class T>
void BinaryTree<T>::preorderD(node<T> *p)
{
    if (p != NULL)
    {
        std::cout << p->info << " ";
        preorderD(p->llink);
        preorderD(p->rlink);
    }
}

template <class T>
void BinaryTree<T>::insert( node<T> *curr, node<T> *n){
	if( n->info < curr->info ){
		if(curr->llink == NULL){
			curr->llink = n;
			return;
		}else{
			insert(curr->llink, n);
		}
	}else{
		if(curr->rlink == NULL){
			curr->rlink = n;
			return;
		}else{
			insert(curr->rlink,n);
		}
	}
}

template <class T>
void BinaryTree<T>::postorderD(node<T> *p)
{
    if (p != NULL)
    {
        postorderD(p->llink);
        postorderD(p->rlink);
        std::cout << p->info << " ";
    }
}

template <class T>
int BinaryTree<T>::max(int x, int y)
{
    if (x >= y)
        return x;
    return y;
}

template <class T>
int BinaryTree<T>::height(node<T> *p)
{
    if (p == NULL)
        return 0;
    else
        return 1 + max(height(p->llink), height(p->rlink));
}

template <class T>
int BinaryTree<T>::nodecount(node<T> *p)
{
    if (p == NULL)
        return 0;
    else
        return 1 + nodecount(p->llink) + nodecount(p->rlink);
}

template <class T>
int BinaryTree<T>::leavescount(node<T> *p)
{
    if (p == NULL)
        return 0;
    else if (p->rlink == NULL && p->link == NULL)
        return 1;
    else
        return leavescount(p->llink) + leavescount(p->rlink);
}

// updated function

/**
* function to count, number of nodes, which have single child
*/
template<typename T>
int numberOfOnes(node<T> *n){
	int num = 0;
	if(n == NULL){
		return 0;
	}
	
	num += numberOfOnes(n->llink); // call left sunttree of current node
	num += numberOfOnes(n->rlink); // call right subtree of current node
	
	if((n->llink != NULL && n->rlink == NULL) || (n->llink == NULL && n->rlink != NULL)){
		return num+1; // if current node have single child then return num + 1;
	}else{
		return num+0;
	}
}

#endif
