#include <iostream>
#include <vector>
using namespace std;

int main(){
	// create a vrcor instance pointers to integers
	vector<int*> ptoi;
	
	// initialize pointers to specific memory location
	ptoi.push_back(new int(2));
	ptoi.push_back(new int(3));
	ptoi.push_back(new int(45));
	
	// create a constant refrence to original vector
	const vector<int *> *cptoi = &ptoi;	
	
	// try to change integer integer pointed by pointer of vector at index 0
	// generate an error 
	// yes, it is now impossible to modify anyone of the integers pointed to by one of the pointers in the vector
	// because we were trying to change a pointing refrence of a constant pointer, that generate an error
	// [Error] assignment of read-only location 'cptoi->std::vector<_Tp, _Alloc>::operator[]<int*, std::allocator<int*> >(0ull)'
	// uncomment below line and check error
	// (*cptoi)[0] = new int(78);
	
	// but we can change value of integer without any error
	// because we initialize pointer as constant variable so we can not modify value of any pointers, but we can modify the value of integers pointer
	// pointed by these constant pointers
	// const keyword declare memory of variable as read only memory
	*(*cptoi)[0] = 78;
	
	for (int i=0; i<cptoi->size(); i++){
		cout<<*(*cptoi)[i]<<endl;
	}	
}
