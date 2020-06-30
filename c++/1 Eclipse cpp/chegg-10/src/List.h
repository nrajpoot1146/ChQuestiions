#include <iostream>
using namespace std;

template <class T, const int CAPACITY>
class List
{
   //private members
private:

   int num_used;
   int cur_pos;

public:

   T arr[CAPACITY];
   //default constructor
   List()
   {
       num_used = 0;
       cur_pos = -1;
   }

   //copy constructor
   List(const List& list)
   {
       num_used = list.num_used;
       for (int i = 0; i < num_used; i++)
       {
           arr[i] = list.arr[i];
       }
   }

   //returns true or false if list is empty or not.
   bool empty()
   {
       return ((num_used == 0) ? true : false);
   }

   //makes current position at the beginning of the list
   void first()
   {
       cur_pos = 0;
   }

   //makes current position at the end of a list
   void last()
   {
       cur_pos = num_used - 1;
   }

   //places current position at the previous element in the list
   void prev()
   {
       cur_pos--;
   }

   void next()
   {
       cur_pos++;
   }

   //returns current position or where you are in the list
   int getpos()
   {
       return cur_pos;
   }

   //places current position in a certain position in the list
   void setpos(int i)
   {
       if (i >= 0 && i < num_used)
           cur_pos = i;
   }

   //inserts a new element before the current position
   void insertbefore(int item)
   {
       for (int i = num_used; i >= cur_pos; i--)
           arr[i + 1] = arr[i];
       arr[cur_pos] = item;
       num_used++;
   }

   //inserts a new element after the current position
   void insertafter(int item)
   {
       cur_pos++;
       for (int i = num_used; i >= cur_pos; i--)
           arr[i + 1] = arr[i];
       arr[cur_pos] = item;
       num_used++;
   }

   //returns the one element that current position is pointing to
   T getelement()
   {
       return arr[cur_pos];
   }

   //returns the size of the list (number of elements in list)
   int size()
   {
       return num_used;
   }

   //replace the current element with a new value
   void replace(T item)
   {
       arr[cur_pos] = item;
   }

   //deletes the current element
   T erase()
   {
       int i;
       T item = arr[cur_pos];
       for ( i = cur_pos; i < num_used - 1; i++)
           arr[i] = arr[i + 1];
       num_used--;
       return arr[i];
   }

   //makes the list an empty list
   void clear()
   {
       num_used = 0;
       cur_pos = -1;
   }

   // << operator overloading
   friend ostream& operator<<(ostream &out, const List &list)
   {
       out << endl << "[";
       for (int i = 0; i < list.num_used; i++)
           out << list.arr[i] << " ";
       out << "]" << endl;

       return out;
   }

   // == operator overloading
   bool operator==(const List &list)
   {
       if (num_used != list.num_used)
           return false;
       for (int i = 0; i < num_used; i++)
       {
           if (arr[i] != list.arr[i])
               return false;
       }
       return true;
   }

   // != operator overloading
   bool operator!=(const List &list)
   {
       if (num_used != list.num_used)
           return true;
       for (int i = 0; i < num_used; i++)
       {
           if (arr[i] != list.arr[i])
               return true;
       }
       return false;
   }

   // = operator overloading
   List& operator=(const List &list)
   {
       num_used = list.num_used;
       for (int i = 0; i < num_used; i++)
       {
           arr[i] = list.arr[i];
       }
       return *this;
   }

   // + operator overloading
   List operator+(const List &b)
   {
       List a;

       a.num_used = num_used + b.num_used;
       for (int i = 0; i < num_used; i++)
       {
           a.arr[i] = arr[i];
       }

       for (int k = 0; k < b.num_used; k++)
       {
           a.arr[num_used + k] = b.arr[k];
       }

       return a;
   }

   // += operator overloading
   List& operator+=(const List &b)
   {
       for (int k = 0; k < b.num_used; k++)
       {
           arr[num_used + k] = b.arr[k];
       }
       num_used = num_used + b.num_used;

       return *this;
   }
};
