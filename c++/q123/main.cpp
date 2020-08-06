#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

// required class
template<typename T>
class Tv_show_info{
	public:
		vector<T> info; // vector variable to store info
		Tv_show_info(string filename){
			ifstream ifs;
			ifs.open(filename.c_str());
			
			if (!ifs.good()){
				cout<<"Input file does not exist.\n";
				return;
			}
			
			string line;
			string firstline;
			getline(ifs, firstline);// read first line from file
			while(!ifs.eof()){
				getline(ifs, line); // read next line from file
				if (ifs.eof()){
					break;
				}
				
				if (firstline == "Viewer"){ // if first line is  Viewer store data as integer
					stringstream ss;
					ss<<line;
					T num;
					ss>>num;
					info.push_back(num);
				} else if (firstline == "Show"){ // if first line is Show store data as string
					stringstream ss;
					ss<<line;
					char c;
					T t;
				    while (ss.get(c)) {
				        if (isalpha(c) || isspace(c))
				            t = t + c;
				    }
					
					info.push_back(t);
				}
			}
		}
};

int main(int argc, char** argv){
	Tv_show_info<int> viewers("file1.txt");
	Tv_show_info<std::string> show_names(argv[2]);
	
	// print all data to console window
	for (int i=0; i<viewers.info.size(); i++){
		int n = viewers.info.at(i);
		std::string s = show_names.info.at(i);
		cout<<s<<" "<<n<<endl;
	}
}
