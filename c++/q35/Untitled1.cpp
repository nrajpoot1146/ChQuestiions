#include<iostream>
#include<string>
#include<sstream>
#define nullptr '\0'
using namespace std;

struct PolyNode{
	int coefficient;
	int power;
	PolyNode *Next;
	PolyNode(int c = 1, int pwr = 0, PolyNode * ptr = nullptr) : coefficient(c), power(pwr), Next(ptr){
	
	}
   const string toString() const{
   		stringstream ss,ss1;
   		ss<<this->coefficient;
   		ss1<<this->power;
		return "Cofficient: "+ ss.str() +"Power: "+ss1.str();
   }
};

struct PolyLinkedList{
	PolyNode *HeadPtr;
	PolyNode *TailPtr;
	size_t size;
	PolyLinkedList():HeadPtr(new PolyNode('A','B',nullptr)){
		TailPtr = HeadPtr;
		this->size = 0;
	}
	
	void copy(const PolyLinkedList &PLL){
		this->HeadPtr = PLL.HeadPtr;
	}
	
	void destroy(){
		delete this->HeadPtr;
	}
	
	PolyLinkedList(const PolyLinkedList &OtherPoly){
		if (this == &OtherPoly){
			cout<<"Self copy are not allowed";
		}else{
			this->copy(OtherPoly);
		}
	}
	
	const PolyLinkedList & operator = (const PolyLinkedList &OtherPoly){
		this->copy(OtherPoly);
		return *this;
	}
	
	virtual ~PolyLinkedList(){
		this->destroy();
	}
	
	void insertInOrder(int c, int p){
		PolyNode *newNode = new PolyNode(c, p, nullptr);
		this->TailPtr->Next = newNode;
		this->TailPtr = newNode;
		this->size++;
	}
	
	void insertFront(int c, int p){
		PolyNode *newNode = new PolyNode(c, p, this->HeadPtr);
		this->HeadPtr = newNode;
		this->size++;
	}
	
	void insertTail(int c, int p){
		PolyNode *newNode = new PolyNode(c, p, nullptr);
		this->TailPtr->Next = newNode;
		this->TailPtr = newNode;
		this->size++;
	}
	
	size_t getSize(){
		return this->size;
	}
};

int main(){
	
}
