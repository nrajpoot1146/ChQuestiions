#include<iostream>

/**
 * default constructor
 * initialize initial bag itemcount = 0
 * intialize maxitem to default max capacity
 */
template<class ItemType>
ArrayBag<ItemType>::ArrayBag(){
	this->itemCount = 0;
	this->maxItems = DEFAULT_CAPACITY;
};

/**
 * @return current items count
 */
template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const{
	return this->itemCount; 
}

/**
 * @return true if bag is empty otherwise false
 */
template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const{
	if(this->itemCount == 0){
		return true; 
	}
	return false;
}

/**
 * @param newEntry new value to be added
 * @return true if item is added otherwise return false
 */
template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry){
	if(this->itemCount == this->maxItems){
		return false;
	}
	this->items[this->itemCount] = newEntry; //add item into bag
	this->itemCount++;
}

/**
 * remove an item from bag
 * @param anEntry item to be remove
 * @return true if item removed successfully
 */
template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry){
	if(this->isEmpty()){
		return false;
	}
	int i=0;
	while(i<this->itemCount){
		if(this->items[i] == anEntry){
			
			while(i < this->itemCount-1){
				this->items[i] = this->items[i+1];
				i++;
			}
			
			this->itemCount--; //decrement by one in itemcount
			return true;
		}
		i++;
	}
	return false;
	
}

/**
 * set itemcount to zero
 */
template<class ItemType>
void ArrayBag<ItemType>::clear(){
	this->itemCount = 0;
}

/**
 * find wether nag contains an item or not 
 * @param anEntry item to be find
 * @return true if given entry is find otherwise return false
 */
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const{
	if(this->isEmpty()){
		return false;
	}
	int i=0;
	while(i<this->itemCount){
		if(this->items[i] == anEntry){
			return true;
		}
		i++;
	}
	return false;
}


/**
 * calculate frequency of any item
 * @param anEntry for which frequency is calculated
 * @return return -1 if bag is empty, return 0 if frequency count is 0 otherwise return a positive integer number
 */
template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const{
	if(this->isEmpty()){
		return -1;
	}
	int count = 0;
	int i=0;
	while(i<this->itemCount){
		if(this->items[i] == anEntry){
			count++;
		}
		i++;
	}
	return count;
}

/**
 * find intersectionn of two bag
 * @param otherBag
 * @return intersection of both bag
 */
template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::bagIntersection(const ArrayBag<ItemType> &otherBag) const{
	ArrayBag<ItemType> newBag;
	int i=0;
	while(i < this->itemCount){
		if(newBag.contains(this->items[i])){
			i++;
			continue;
		}
		int f1 = this->getFrequencyOf(this->items[i]); // frequency of an item in bag 1
		int f2 = otherBag.getFrequencyOf(this->items[i]); // frequency of an item in bag 2
		
		int finalFreq = f1 > f2 ? f2 : f1;
		
		if(finalFreq > 0){
			int j=0;
			while(j < finalFreq){
				newBag.add(this->items[i]); // put an item to new bag with minimum frequency if item is present in both bag
				j++;
			}
		}
		i++;
	}
	return newBag;
}

/**
 * @return a verctor array of bag
 */
template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const{
	int i = 0;
	std::vector<ItemType> v;
	while(i < this->itemCount){
		v.push_back(this->items[i]);
		i++;
	}
	return v;
}

