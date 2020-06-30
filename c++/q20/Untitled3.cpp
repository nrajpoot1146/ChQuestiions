#include<iostream>
#include"ArrayBag.h"

using namespace std;

template<class itemtype>
void displayBag(ArrayBag<itemtype> &bag)
{
vector<itemtype> bagItems = bag.toVector();

int n = (int)bagItems.size();
  
for (int i = 0; i < n; i++){
cout << bagItems[i] << " ";
}
  
cout << std::endl<< std::endl;
}

int main(){
   ArrayBag<int> bag1,bag2,bag3;
  
   cout<<"First bag: The bag contains 5 items:"<<endl;
   // add items of first bag
   bag1.add(1);
   bag1.add(2);
   bag1.add(3);
   bag1.add(4);
   bag1.add(5);
   displayBag(bag1);
  
   // add items of second bag
   cout<<"\nSecond bag: The bag contains 5 items:"<<endl;
   bag2.add(20);
   bag2.add(30);
   bag2.add(40);
   bag2.add(50);
   bag2.add(1);
   displayBag(bag2);
  
   // call intersection function to calculate intersection of both bag bag1 and bag2
   bag3 = bag1.bagIntersection(bag2);
   // print all item of third bag
   cout<<"\nThe bag containing the Intersection of these bag: The bag contains "<<bag3.getCurrentSize()<<" items: "<<endl;
   displayBag(bag3);
  
   ArrayBag<string> sbag1,sbag2,sbag3;


   cout<<"First bag: The bag contains 5 items:"<<endl;
   // add items of first bag
   sbag1.add("one");
   sbag1.add("two");
   sbag1.add("three");
   sbag1.add("four");
   sbag1.add("five");
   displayBag(sbag1);
  
   // add items of second bag
   cout<<"\nSecond bag: The bag contains 5 items:"<<endl;
   sbag2.add("twenty");
   sbag2.add("thirty");
   sbag2.add("fourty");
   sbag2.add("fifty");
   sbag2.add("one");
   displayBag(sbag2);
   // call intersection function to calculate intersection of both bag bag1 and bag2
   sbag3 = sbag1.bagIntersection(sbag2);
   // print all item of third bag
   cout<<"\nThe bag containing the Intersection of these bag: The bag contains "<<bag3.getCurrentSize()<<" items: "<<endl;
   displayBag(sbag3);
}
