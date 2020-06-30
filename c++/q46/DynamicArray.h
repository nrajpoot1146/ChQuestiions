
/**
* class to create dynamic array
*/
template<class T>
class DynamicArray{
	private:
		T *p; // pointer to store address of dynamic array
		int numCounts; // a counter varible, number of elements in dynamic array
		
		/**
		* function to grow array size by one;
		*/
		void grow(){
			T *temp = new T[numCounts+1];
			for (int i=0; i<numCounts; i++){
				temp[i] = p[i];
			}
			delete[] p;
			p = temp;
		}
	public:
		DynamicArray(){
			numCounts = 0;
			p = NULL;
		}
		
		/**
		* funtion to add an element in array
		*/
		void add(T ele){
			this->grow();
			this->p[numCounts] = ele;
			numCounts++;
		}
		
		T operator[](int index){
			return this->p[index];
		}
		
		int size(){
			return this->numCounts;
		}
		
};
