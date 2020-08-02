#include<iostream>
#include<fstream>
#include<stack>
using namespace std;

// return true if file contains all currect matching otherwise return false
bool isCorrect(ifstream &ifs){
	stack<string> stk;
	string line;
	do {
		getline(ifs, line);
		if (line.find("begin") != string::npos){
			stk.push("begin");
		} else if (line.find("{") != string::npos){
			stk.push("{");
		} else if (line.find("(") != string::npos){
			stk.push("(");
		} else if (line.find("[") != string::npos){
			stk.push("[");
		} else if (line.find("end") != string::npos){
			if (stk.top() != "begin")
				return false;
			stk.pop();
		} else if (line.find("}") != string::npos){
			if (stk.top() != "{")
				return false;
			stk.pop();
		} else if (line.find(")") != string::npos){
			if (stk.top() != "(")
				return false;
			stk.pop();
		} else if (line.find("]") != string::npos){
			if (stk.top() != "]")
				return false;
			stk.pop();
		}

	} while (!ifs.eof());
	
	if (stk.empty()){
		return true;
	}
	return false;
}

int main(){
	ifstream ifs;
	ifs.open("input.txt");
	
	// check input.txt file have currect matching of not
	if (isCorrect(ifs)){
		cout<<"file contains all correct matching.";
	} else {
		cout<<"file not contains all correct matching.";
	}
	
	ifs.close();
}
