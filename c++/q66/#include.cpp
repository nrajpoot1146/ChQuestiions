/**
* name: main.cpp
* @author: 
*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct student{
    char name[50];
    float quiz[3][2];
    float avg;
};

int num; // variable to store number of students

/**
* read data from user
* generate array of students dynamically
* calculate average marks of students
* @return pointer of array of student
*/
student *input(){
	cout<<"Enter the total number of students: ";
	cin>>num; // read number of students
	cin.ignore();
	student *s = new student[num];
	
	for (int i = 0; i < num; i++){
		cout<<"Enter name: ";
		gets(s[i].name); // read student name
		int sum = 0;
		cout<< "Enter marks: ";
		for (int j = 0; j < 3; j++){
			for (int k = 0; k < 2; k++){
				cin>>s[i].quiz[j][k]; // read quize marks
				sum += s[i].quiz[j][k];
			}
		}
		s[i].avg = sum / 6.0; // calculate average
		cin.ignore();
	}
	return s;
}

/**
* display student quize marks
* display average marks of each student
* display average marks of each quize
*/
void display(student *s){
	float quizAvg[3][2] = {0};
	cout<<"name\t\t\tQuiz 1\tQuiz 2\tQuiz 3\tQuiz 4\tQuiz 5\tQuiz 6\tindividual's Average\n";
	for (int i = 0; i<num; i++){
		cout<<s[i].name<<"\t\t";
		for (int j = 0; j < 3; j++){
			for (int k = 0; k < 2; k++){
				cout<<s[i].quiz[j][k]<<"\t";
				quizAvg[j][k] += s[i].quiz[j][k];
			}
		}
		cout<<setprecision(3)<<s[i].avg;
		cout<<endl;
	}
	cout<<"Quiz Average \t\t";
	for (int j = 0; j < 3; j++){
		for (int k = 0; k < 2; k++){
			cout<<quizAvg[j][k]/2.0<<"\t";
		}
	}
	
}

/**
* open text file 
* write student quize marks
* write average marks of each student
* write average marks of each quize
*/
void save_in_file(ofstream &fout, student *s){
	fout.open("output.txt");
	
	float quizAvg[3][2] = {0};
	fout<<"name\t\t\tQuiz 1\tQuiz 2\tQuiz 3\tQuiz 4\tQuiz 5\tQuiz 6\tindividual's Average\n";
	for (int i = 0; i<num; i++){
		fout<<s[i].name<<"\t\t";
		for (int j = 0; j < 3; j++){
			for (int k = 0; k < 2; k++){
				fout<<s[i].quiz[j][k]<<"\t";
				quizAvg[j][k] += s[i].quiz[j][k];
			}
		}
		fout<<setprecision(3)<<s[i].avg;
		fout<<endl;
	}
	fout<<"Quiz Average \t\t";
	for (int j = 0; j < 3; j++){
		for (int k = 0; k < 2; k++){
			fout<<quizAvg[j][k]/2.0<<"\t";
		}
	}
	fout.flush();
	fout.close();
}

int main(){
	student *s;
	ofstream fout;
	s = input();
	display(s);
	save_in_file(fout, s);
}
