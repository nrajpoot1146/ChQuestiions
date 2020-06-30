#include<string>
using namespace std;
class Professors{
	long id;
	string name;
	string department;
	string email;
	
	public:
		Professors(long id, string name, string department, string email):id(id), name(name), department(department), email(email){
			
		}
		
		string getEmail(){
			return this->email;
		}
		
		long getId(){
			return this->id;
		}
		
		string getName(){
			return this->name;
		}
		
		string getDepartment(){
			return this->department;
		}
		
};
