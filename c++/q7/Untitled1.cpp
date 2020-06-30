#include<iostream>

using namespace std;

struct nodeType {
  int info;
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
  void insertFirst(int val) {
    nodeType * c;
    c = new nodeType;
    c - > info = val;
    c - > link = 0;
    if (head == 0)
      head = c;
    else {
      c - > link = head;
      head = c;
    }
  }

  void insertLast(int val) {
    nodeType * p;
    p = new nodeType;
    p - > info = val;
    p - > link = 0;
    if (head == 0)
      head = p;
    else {
      nodeType * c;
      c = new nodeType;
      c = head;
      while (c - > link != 0)
        c = c - > link;
      c - > link = p;
    }
  }

  void insertAfter(int loc, int val) {
    int count = 0;
    nodeType * p;
    p = new nodeType;
    p - > info = val;
    p - > link = 0;
    if (head == 0)
      head = p;
    else {
      nodeType * c;
      c = head;
      while (count < loc && c - > link != 0) {
        c = c - > link;
        count++;
      }
      if (loc > count)
        return;
      else {
        p - > link = c - > link;
        c - > link = p;
      }
    }
  }

  void insertBefore(int loc, int val) {
    if (loc < 0)
      return;
    nodeType * p;
    p = new nodeType;
    int count = 0;
    p - > info = val;
    p - > link = 0;
    if (head == 0)
      head = p;
    else {
      nodeType * c = head;
      while (count < (loc - 1)) {
        c = c - > link;
        count++;
      }
      p - > link = c - > link;
      c - > link = p;
    }
  }

  void initializeList() {
    destroyList();
  }
  void destroyList() {
    nodeType * q;
    while (head != 0) {
      q = head;
      head = head - > link;
      delete q;

    }
  }

  bool isEmpty() {
    return (head == 0);
  }

  void print() {
    nodeType * curent = head;
    if (head != 0) {
      cout << curent - > info;
      curent = curent - > link;
      while (curent != NULL) {
        cout << ",";
        if ((curent - > info) < 10)
          cout << "00" << curent - > info;
        else if ((curent - > info) < 100)
          cout << "0" << curent - > info;
        else
          cout << curent - > info;
        curent = curent - > link;
      }
      cout << endl;
    }

  }

  int getNth(int index) {
    int i = 1;
    nodeType * current = head;
    while (i != index && current != NULL) {
      current = current - > link;
      i++;
    }
    return current - > info;
  }

  int length() {
    nodeType * c;
    c = head;
    int count = 0;
    while (c != 0) {
      c = c - > link;
      count++;
    }
    return count;
  }

  char front() {
    if (!isEmpty())
      return (head - > info);
    return -1;
  }
  char back() {
    nodeType * curent = head;
    while (curent - > link != NULL)
      curent = curent - > link;

    return (curent - > info);
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
        p - > info = c - > info;
        p - > link = NULL;
        c = c - > link;
        head = p;
        while (c != 0) {
          p - > link = new nodeType;
          p = p - > link;
          p - > info = c - > info;
          p - > link = 0;
          c = c - > link;
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
      int ele;
      cout << "Enter Huge Int: ";
      cin >> ele;
      obj1.insertFirst(ele);
      obj1.print();
    } else if (o == 2) {
      int ele;
      cout << "Enter Huge Int: ";
      cin >> ele;
      obj1.insertFirst(ele);
      obj1.print();

    } else if (o == 3) {
      obj1.print();
    } else if (o == 4) { // +operation
      cout << obj1.getNth(1) << endl;
      cout << "+" << obj1.getNth(2) << endl;
      cout << obj1.getNth(1) + obj1.getNth(2) << endl;
    } else if (o == 5) { // -opeartion
      cout << obj1.getNth(1) << endl;
      cout << "-" << obj1.getNth(2) << endl;
      cout << obj1.getNth(1) - obj1.getNth(2) << endl;
    } else if (o == 6) { // *operation
      cout << obj1.getNth(1) << endl;
      cout << "*" << obj1.getNth(2) << endl;
      cout << obj1.getNth(1) * obj1.getNth(2) << endl;
    } else if (o == 7) { // exit
      break;
    }
  }
}
