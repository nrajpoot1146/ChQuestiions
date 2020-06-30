#include<string>
using namespace std;
class Courses{
	string name;
	float registerd_students;
	
	public:
		Courses(string name, float registerdStudents):name(name),registerd_students(registerd_students){
			
		}
		
		Courses(string name):name(name),registerd_students(0){
			
		}
		
		string getName(){
			return this->name;
		}
		
		float getRegisterdStudent(){
			return this->registerd_students;
		}
		
		void setName(string name){
			this->name = name;
		}
		
		void setRegisteredStudent(float n){
			this->registerd_students = n;
		}
		
		float operator ++(int){
			this->registerd_students++;
		}
};
