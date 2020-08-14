#include <iostream>
using namespace std;

class line {
	public:
		// default constructor
		// calls setValues()
		line();
		
		// overloaded copy constructor
		line(const line &Line);
		
		// read data from user
		// use stdin for input
		void setValues();
		
		// print equation
		// int form ax + by + c
		void printEquation();
		
		// friend function to calculate
		// intersection point between two line
		friend void calIntersection(line &l1, line &l2);
	private:
		double a, b, c;
};

line::line(){
	this->setValues();
}

line::line(const line &Line) {
	this->a = Line.a;
	this->b = Line.b;
	this->c = Line.c;
}

void line::setValues() {
	cout<<"Enter the value of coefficient a: ";
	cin>>this->a;
	cout<<"Enter the value of coefficient b: ";
	cin>>this->b;
	cout<<"Enter the value of coefficient c: ";
	cin>>this->c;
}


void line::printEquation() {
	cout<<a<<"x";
	if (b<0) {
		cout<<" - ";
	} else {
		cout<<" + ";
	}
	
	cout<<b<<"y";
	
	if (c<0) {
		cout<<" - ";
	} else {
		cout<<" + ";
	}
	cout<<c;
}

// function to calculate intersection point
// (x, y) between two given lines
void calIntersection(line &l1, line &l2) {
	if ((l1.a == 0 && l1.b == 0 && l1.c == 0) 
	|| (l2.a == 0 && l2.b == 0 && l2.c == 0)) {
		throw "Error: cofficient is not valid\n";
	}
	
	if (l1.a == l2.a && l1.b == l2.b && l1.c == l2.c ){
		throw "Error: given equations are same\n";
	}
	
	if (l1.a == l2.a && l1.b == l2.b && l1.c != l2.c) {
		throw "Error: given equations are parallel\n";
	}
	
	double x, y;
	
	x = (l1.c * l2.b - l2.c * l1.b) / (l2.a * l1.b - l1.a * l2.b);
	y = (l1.c * l2.a - l2.c * l1.a) / (l2.b * l1.a - l1.b * l2.a);
	
	cout<<"Intersection point between lines (";
	l1.printEquation();
	cout<<" and ";
	l2.printEquation();
	cout<<") is (x, y): ("<<x<<", "<<y<<")\n";
}

int main() {
	line l1, l2; // declare two line objects
	
	try {
		calIntersection(l1, l2); // cal intersection points
	} catch (const char *str){
		cout<<str;
	}
}
