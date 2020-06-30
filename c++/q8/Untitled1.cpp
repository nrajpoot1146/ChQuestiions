#include<iostream>
#include <iomanip>

using namespace std;

struct nodeType {
  long long info;
  nodeType * link;
};

class linkedListType {
  public:

    linkedListType() {
      head = new nodeType;
      head = 0;
    }~linkedListType() {
      destroyList();
    }
  void insertFirst(long long val) {
    nodeType * c;
    c = new nodeType;
    c -> info = val;
    c -> link = 0;
    if (head == 0)
      head = c;
    else {
      c -> link = head;
      head = c;
    }
  }

  void insertLast(long long val) {
    nodeType * p;
    p = new nodeType;
    p -> info = val;
    p -> link = 0;
    if (head == 0)
      head = p;
    else {
      nodeType * c;
      c = new nodeType;
      c = head;
      while (c -> link != 0)
        c = c -> link;
      c -> link = p;
    }
  }

  void insertAfter(int loc, long long val) {
    int count = 0;
    nodeType * p;
    p = new nodeType;
    p -> info = val;
    p -> link = 0;
    if (head == 0)
      head = p;
    else {
      nodeType * c;
      c = head;
      while (count < loc && c -> link != 0) {
        c = c -> link;
        count++;
      }
      if (loc > count)
        return;
      else {
        p -> link = c -> link;
        c -> link = p;
      }
    }
  }

  void insertBefore(int loc, long long val) {
    if (loc < 0)
      return;
    nodeType * p;
    p = new nodeType;
    int count = 0;
    p -> info = val;
    p -> link = 0;
    if (head == 0)
      head = p;
    else {
      nodeType * c = head;
      while (count < (loc - 1)) {
        c = c -> link;
        count++;
      }
      p -> link = c -> link;
      c -> link = p;
    }
  }

  void initializeList() {
    destroyList();
  }
  void destroyList() {
    nodeType * q;
    while (head != 0) {
      q = head;
      head = head -> link;
      delete q;

    }
  }

  bool isEmpty() {
    return (head == 0);
  }

  void print() {
    nodeType * curent = head;
    if (head != 0) {
      cout << curent -> info;
      curent = curent -> link;
      while (curent != NULL) {
        cout << ",";
        if ((curent -> info) < 10)
          cout << "00" << curent -> info;
        else if ((curent -> info) < 100)
          cout << "0" << curent -> info;
        else
          cout << curent -> info;
        curent = curent -> link;
      }
      cout << endl;
    }

  }

  long long getNth(int index) {
    int i = 1;
    nodeType * current = head;
    while (i != index && current != NULL) {
      current = current -> link;
      i++;
    }
    return current -> info;
  }
  
  string format(long long val){
  	int count = 0 ;//number of digit
  	long long temp = val;
  	int countCom = 0;
  	while(temp != 0){
  		temp/=10;
  		count++;
	  }
	
	if(count % 3 == 0){
		countCom = (count/3) -  1;
	}else{
		countCom = (count / 3);
	}
	
	int totalChar = count + countCom;
	
	char res[totalChar+1];
	res[totalChar] = '\0';
	int mod;
	int i=0;
	while(totalChar--){
		if(i == 3){
			res[totalChar] = ',';
			i=0;
			continue;
		}
		int mod = val % 10;
		res[totalChar] = mod + '0';
		i++;
		val = val/10;
	}
	
	return res;
  }

  int length() {
    nodeType * c;
    c = head;
    int count = 0;
    while (c != 0) {
      c = c -> link;
      count++;
    }
    return count;
  }

  char front() {
    if (!isEmpty())
      return (head -> info);
    return -1;
  }
  char back() {
    nodeType * curent = head;
    while (curent -> link != NULL)
      curent = curent -> link;

    return (curent -> info);
  }

  protected:
    nodeType * head;
  public:
    void copyList(const linkedListType & cf) {
      nodeType * p;
      nodeType * c;
      c = cf.head;
      if (cf.head == 0)
        head = 0;

      else {
        head = new nodeType;
        p = head;
        p -> info = c -> info;
        p -> link = NULL;
        c = c -> link;
        head = p;
        while (c != 0) {
          p -> link = new nodeType;
          p = p -> link;
          p -> info = c -> info;
          p -> link = 0;
          c = c -> link;
        }

      }
    }
};
int main() {
  linkedListType obj1;

  while (true) {
    cout << "Menu" << endl;
    cout << "1. Enter first HugeInt" << endl;
    cout << "2. Enter second HugeInt" << endl;
    cout << "3. Print first and Second HugeInt" << endl;
    cout << "4. Perform + and print operands and result." << endl;
    cout << "5. Perform - and print operands and result." << endl;
    cout << "6. Perform * and print operands and result." << endl;
    cout << "7. Exit" << endl;

    int o = 0;
    cin >> o;

    if (o == 1) {
      long long ele;
      cout << "Enter Huge Int: ";
      cin>>ele;
      obj1.insertFirst(ele);
      cout<<obj1.format(ele)<<endl;
    } else if (o == 2) {
      long long ele;
      cout << "Enter Huge Int: ";
      cin >> ele;
      obj1.insertLast(ele);
      cout<<obj1.format(ele)<<endl;

    } else if (o == 3) {
      obj1.print();
    } else if (o == 4) { // +operation
      cout << setw(26) << obj1.format(obj1.getNth(1))<<endl;
      cout << setw(26) << "+" + obj1.format(obj1.getNth(2)) << endl;
      cout <<"--------------------------"<<endl;
      cout << setw(26) << obj1.format(obj1.getNth(1) + obj1.getNth(2)) << endl;
    } else if (o == 5) { // -opeartion
      cout << setw(26) << obj1.format(obj1.getNth(1))<<endl;
      cout << setw(26) << "-" + obj1.format(obj1.getNth(2)) << endl;
      cout <<"--------------------------"<<endl;
      cout << setw(26) << obj1.format(obj1.getNth(1) - obj1.getNth(2)) << endl;
    } else if (o == 6) { // *operation
      cout << setw(26) << obj1.format(obj1.getNth(1))<<endl;
      cout << setw(26) << "*" + obj1.format(obj1.getNth(2)) << endl;
      cout <<"--------------------------"<<endl;
      cout << setw(26) << obj1.format(obj1.getNth(1) * obj1.getNth(2)) << endl;
    } else if (o == 7) { // exit
      break;
    }
  }
}
