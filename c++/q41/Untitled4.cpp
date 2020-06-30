#include <iostream>
#include <string>

using namespace std;

class Contact
{
   private:
       string phone;
   public:
       Contact(string phone)
       {
           this->phone = phone;
       }
       string getPhone() const{  
           return this->phone;
       }
       void setPhone(string phone){
           this->phone = phone;
       }
};

class Address
{
   private:
       string home;
       string quarantine;
   public:
       Address(string home,string quarantine)
       {
           this->home = home;
           this->quarantine = quarantine;
       }
       string getHome() const{
           return this->home;
       }
       string getQuaranPlace() const{
           return this->quarantine;
       }
       void setHome(string home){
           this->home = home;
       }
       void setQuaranPlace(string quarantine)
       {
           this->quarantine = quarantine;
       }
};

class Person{
   private:
       string name;
   public:
       Person(string name)
       {
           this->name = name;
       }
       string getName() const{
           return this->name;
       }
       void setName(string name)
       {
           this->name = name;
       }
       
       virtual void printDetails(){
       		cout<<"Name: "<<this->name<<endl;
	   }

};

class Detail
{
   private:
       string matrix;
       string ic;
   public:
       Detail(string matrix,string ic)
       {
           this->matrix = matrix;
           this->ic = ic;
       }
       string getMatrix() const
       {
           return this->matrix;
       }
       string getIC() const{
           return this->ic;
       }
};

class Student:public Person
{
   private:
       Detail info;       //Aggregration
       Contact* number;   //Composition
       Address* location;
   public:
       Student(string matrix,string ic,string name,Contact* number,Address* location):Person(name),info(matrix,ic)
       {
           // info = new Detail(matrix,ic);
           this->number = number;
           this->location = location;
       }
       //Operator overloading
       friend ostream& operator<<(ostream& out, Student& st)
       {
           out << "Name:" << st.getName() <<endl;
           out << "Matrix No:"<<st.info.getMatrix()<<endl;
           out << "ID No:"<<st.info.getIC()<<endl;
           out << "Phone No:"<<st.number->getPhone()<<endl;
           out << "Home:"<<st.location->getHome()<<endl;
           out << "Quarantine Place:"<<st.location->getQuaranPlace()<<endl;
           return out;
       }
       
       // polymorphism 
       virtual void printDetails() {
           Person::printDetails();
           cout << "Matrix No:"<<this->info.getMatrix()<<endl;
           cout << "ID No:"<<this->info.getIC()<<endl;
           cout << "Phone No:"<<this->number->getPhone()<<endl;
           cout << "Home:"<<this->location->getHome()<<endl;
           cout << "Quarantine Place:"<<this->location->getQuaranPlace()<<endl;
       }
};

class International:public Student
{
   private:
       string country;
   public:
       International(string country,string matrix,string ic,string name,Contact* number,Address* location):Student(matrix,ic,name,number,location)
       {
           this->country = country;
       }
       string getCountry() const
       {
           return this->country;
       }
       void setCountry(string country)
       {
           this->country = country;
       }
       void printDetails(){
           cout<<"INTERNATIONAL student from "<<country<<endl;
           Student::printDetails();
       }
};

class Local:public Student
{
   private:
       string state;
   public:
       Local(string state,string matrix,string ic,string name,Contact* number,Address* location):Student(matrix,ic,name,number,location)
       {
           this->state = state;
       }
       string getState() const
       {
           return this->state;
       }
       void setState(string state)
       {
           this->state = state;
       }
       
       // polymorphism
       void printDetails(){
           cout<<"LOCAL student from "<<state<<endl;
           Student::printDetails();
       }
};

int main()
{
   int choice,i;
   string name;

	/*
	* vitual method are dynamicaly bind on runtime show we will use pointer for polymorphism 
	*/
	
   Contact contact_0("0138077759");
   Address address_0("Skudai","KTDI UTM");
   
   // old line: Local stu_0("Johor","A18ES0200","010304012789","John Doe",&contact_0,&address_0);
   Student *stu_0 = new Local("Johor","A18ES0200","010304012789","John Doe",&contact_0,&address_0);

   Contact contact_1("0176653657");
   Address address_1("Queensland","KDSE UTM");
   
   //old line: Local stu_1("Australia","A18ES0235","020603018972","Jane Doe",&contact_1,&address_1);
   Student *stu_1 = new Local("Australia","A18ES0235","020603018972","Jane Doe",&contact_1,&address_1);

   Contact contact_2("0137397654");
   Address address_2("Skudai","Taman Universiti");
   
   //old line: International stu_2("Canada","A19ES0093","010638291723","John Crawford",&contact_2,&address_2);
   Student *stu_2 = new International("Canada","A19ES0093","010638291723","John Crawford",&contact_2,&address_2);

   //Array of objects
   // old line: Student arr[3] = {(Student)stu_0,(Student)stu_1,(Student)stu_2};
   Student *arr[3] = {stu_0, stu_1, stu_2};
   // arr[0] = (Student)stu_0;
   // arr[1] = stu_1;
   // arr[1] = stu_2;

   //Displaying the menu
   cout << "------------------------------------------------------------"<<endl;
   cout << "------------------------------------------------------------"<<endl;
   cout << "MENU"<<endl;
   cout << "1.Display All Students"<<endl;
   cout << "2.Search for a student"<<endl;
   cout << "3.Exit"<<endl;
   cout << "------------------------------------------------------------"<<endl;
   cout << "------------------------------------------------------------"<<endl;
   cout << "Enter choice:"<<endl;
   cin >> choice;

   while(choice==1 || choice==2)
   {
       if (choice == 1)
       {
           cout << "Displaying all students information:"<<endl;
           for (i=0;i<3;i++)
           {
               arr[i]->printDetails(); // old line: cout<<arr[i]<<endl;
               cout<<endl;
           }
       }
       else if(choice == 2)
       {
           cout <<"Student's name you want to look for :"<<endl;
           cin >> name;
           cout << "Displaying all student's information with name " << name<<":"<<endl;
           
           /*
           * exception handling
           * try to find a student with given name
           * if student is find successfully, print student details
           * otherwise throw an exception
           */
           try{
           		bool flag = false;
	           	for (i=0;i<3;i++)
	           {
	               if (arr[i]->getName().find(name) != string::npos)
	               {
	               	   
					   cout<<endl;
	                   arr[i]->printDetails(); // print student details
	                   flag = true;
	                  
	               }
	           }
	           if (flag == false){
	           	throw "Error: Student with name "+name+" is not found "; // throw an exception
			   }
		   }catch (string msg){ // catch throws exception
		   	cout<<msg<<endl; // print exception message
		   }
           
       }
      
   cout << "------------------------------------------------------------"<<endl;
   cout << "------------------------------------------------------------"<<endl;
   cout << "Enter choice:"<<endl;
   cin >> choice;
   }
   cout<<"Exit the program"<<endl;
   return 0;
}
