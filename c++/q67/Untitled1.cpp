#include <cstdlib>
#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
   T data;
   // introduce a 'next' node for doubly linked list
   Node<T>* next;
   Node<T>* previous;
   Node<T>() { previous = NULL; next = NULL; data = 0; } // old: Node<T>() { previous = NULL; data = 0; }
   Node<T>(T t) { previous = NULL; next = NULL; data = t; } // old: Node<T>(T t) { previous = NULL; data = t; }
};

// Convert Singly Linked List to Doubly Linked List
template <typename T>
class SList
{
public:
   Node<T>* head;
   Node<T>* tail;
   // introduce 'head' node for double link
   // old: SList() { tail = NULL; }
   // head is not initalized
   SList() { tail = NULL; head = NULL; } // default constructor
   // appends to tail of list
   void Append(T data)
   {
       Node<T>* pdata = new Node<T>(data);
       if (tail == NULL)
       {
           tail = pdata;
           head = pdata;
       }
       else
       {
       	   tail->next = pdata;
           pdata->previous = tail;
           tail = pdata;
       }
   }
   // prepends to head of list
   void Prepend(T data)
   {
       Node<T>* pdata = new Node<T>(data);
       if (head == NULL)
       {
           head = pdata;
           tail = pdata;
       }
       else
       {
           pdata->next = head;
           head->previous = pdata;
           head = pdata;
       }
   }
   // inserts data after found data
   void InsertAfter(T find, T data)
   {
       Node<T>* datanode = new Node<T>(data);
       Node<T>* frontnode = Search(find);
       
	   
	   // if front node is tailnode
	   if (frontnode == tail){
	   		this->Append(data);
	   		return;
	   }
       
       if (frontnode != NULL)
       {
//           head = datanode;
           Node<T>* Befnode = frontnode->next;
           frontnode->next = datanode;
           datanode->previous = frontnode;
           datanode->next = Befnode;
           Befnode->previous = datanode;
       }
   }
   // inserts data before found data
   void InsertBefore(T find, T data)
   {
       Node<T>* datanode = new Node<T>(data);
       Node<T>* frontnode = Search(find);
       

		
		// if frontnode is head node
		if (frontnode == head){
			this->Prepend(data);
			return;
		}
		
       if (frontnode != NULL)
       {
//           tail = datanode;
           Node<T>* afternode = frontnode->previous;
           frontnode->previous = datanode;
           datanode->next = frontnode;
           datanode->previous = afternode;
           afternode->next = datanode;
       }
   }
   // finds data node and returns it
   Node<T>* Search(T data)
   {
       Node<T>* node = head;
       while (node != NULL && node->data != data) // old: while (node != head && node->data != data)
       {
           node = node->next;
       }
       return node;
   }
   
   // deletes a node from the list
   void Delete(T data)
   {
       Node<T>* frontnode = Search(data);
       if (frontnode == head && frontnode == tail)
       {
           head = NULL;
           tail = NULL;
       }
       else if (frontnode == head)
       {
           head = frontnode->next;
           head->previous = NULL;
       }
       else if (frontnode == tail)
       {
           tail = frontnode->previous;
           tail->next = NULL;
       }
       else
       {
           Node<T> *Nextnode = frontnode->next;
           Node<T> *Prenode = frontnode->previous;
           Nextnode->previous = Prenode;
           Prenode->next = Nextnode;
       }
       delete frontnode;
   }
   // returns number of nodes in list
   int Count()
   {
       Node<T>* node = tail;
       int count = 0;
       while (node != NULL)
       {
           count++;
           node = node->previous;
       }
       return count;
   }
   // returns true if list is empty
   bool IsEmpty()
   {
       return IsEmpty;
   }
   // prints list from tail of list
   void Output()
   {
       Node<T>* rover = tail;
       while (rover != NULL)
       {
           cout << rover->data << '\t';
           rover = rover->previous;
       }
       cout << endl;
   }
   void OutputFhead()
   {
       Node<T>* rover = tail;
       while (rover != NULL)
       {
           cout << rover->data << ((rover == head) ? "h": "") << ((rover == tail) ? "t": "") << endl;
           rover = rover->next;
       }
       cout << endl;
   }
};

template <typename T>
class stack : public SList<T>
{
private:
   SList<T> list;
public:
  
   stack() { }
   void push(T data)
   {
       Prepend(data);
   }
   T pop()
   {
       T data = list.head->data;
       Delete(list.head->data);
       return data;
   }
   T peek()
   {
       return list.head->data;
   }
   bool IsEmpty()
   {
       return IsEmpty;
   }
   int getlength()
   {
       return list.Count();
   }
   void output()
   {
       list.OutputFhead();
   }
};
template <typename T>
class queue:public SList<T>
{
private: SList<T> list;
public:
  
   queue() { }
   void push(T data)
   {
       Append(data);
   }
   T pop()
   {
       T data = list.head->data;
       Delete(list.head->data);
       return data;
   }
   T peek()
   {
       return list.head->data;
   }
   int getlength()
   {
       return list.Count();
   }
   void output()
   {
       list.OutputFhead();
   }
};

int main()
{
   cout << "prepend Test: " << endl;
   int count = 10;
   SList<int> list;
   for (int x = 0; x < count; x++)
   {
       int rnumber = rand() % 100 +1;
       list.Append(rnumber);
       cout << rnumber << "\t";
   }
   cout << endl;
   list.Output();
   cout << "data to prepend:" << endl;
   list.Output();
   cout << endl;
   cout << "list: " << endl;
   list.Output();
   cout << "-----" << endl;
   cout << "count: " << list.Count() << endl;
   cout << "-------" << endl;
   cout << "search test: " << endl;
   Node<int>* search = list.Search(6);
   search != NULL ? cout << "find :" << search->data <<"\t" << "------" << endl : cout << "not found :\t" << "------" << endl; // null pointer checker condition added
   cout << "insert 35 before 68:" << endl;
   list.InsertBefore(68, 35); // old: list.InsertBefore(35, 68);
   list.Output();
   cout << "-----" << endl;
   cout << "insert 35 before 42: " << endl;
   // check prototype of insert before function
   // first parameter if for search and second is for insertion
   list.InsertBefore(42, 35); // old: list.InsertBefore(35, 42);
   list.Output();
   cout << "------" << endl;
   cout << "insert 1 before 68: " << endl;
   list.InsertBefore(68, 1); // old: list.InsertBefore(1, 68);
   list.Output();
   cout << "----" << endl;
   cout << "insert 1 before 42: " << endl;
   list.InsertBefore(42, 1); // old: list.InsertBefore(1, 42);
   list.Output();
   cout << "----" << endl;
   cout << "insert 1 before 35: " << endl;
   list.InsertBefore(35, 1); // old: list.InsertBefore(1, 35);
   list.Output();
}
