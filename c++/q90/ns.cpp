#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>


//using namespace std; *** NOT ALLOWED TO USE NAMESPACE std ***
// function code for namespace NS1
namespace NS1{
	// function to write data to output file from given vector
	void print(const std::vector<int> &v, const std::string &filename){
		std::ofstream ofs;
		ofs.open(filename.c_str()); // open output file
		// write data to output file
		for(int i=0; i<v.size(); i++){
			ofs<<v[i]<<std::endl;
		}
		ofs.close(); // close output file
	}
	
	// function to read data from input file
	// and push into vector
	void read(std::vector<int> &v, const std::string &filename){
		v.clear(); // clear current vector
		std::ifstream ifs;
		ifs.open(filename.c_str()); // open input file
		if(!ifs.good()){ // check file is open or not
			return;
		}
		while(true){
			std::string line;
			getline(ifs, line);
			if (line == ""){
				break;
			}
			
			// convert string to number
			std::stringstream ss;
			ss<<line;
			int num;
			ss>>num;
			v.push_back(num); // push number into vector
			
			if(ifs.eof()){
				break;
			}
		}
		ifs.close();
	}
}

// function code for namespace NS2
namespace NS2{
	// function to write data to output file from given vector
	void print(const std::vector<int> &v, const std::string &filename){
		std::ofstream ofs;
		// open file to apppend data
		ofs.open(filename.c_str(), std::ios::app);
		// write data in reverse order
		for(int i=v.size()-1; i>=0; i--){
			ofs<<v[i]<<std::endl;
		}
		ofs.close();
	}
	
	// read data from input file and append into given vector
	void read(std::vector<int> &v, const std::string &filename){
		std::ifstream ifs;
		ifs.open(filename.c_str()); // open input file
		if(!ifs.good()){ // check file is open or not
			return;
		}
		while(true){
			std::string line;
			getline(ifs, line);
			
			if (line == ""){
				break;
			}
			
			std::stringstream ss;
			ss<<line;
			int num;
			ss>>num;
			v.push_back(num);
			
			if(ifs.eof()){
				break;
			}
		}
		ifs.close();
	}
}

// insertion operator overloading
// print element of vector
std::ostream &operator<< (std::ostream &os, const std::vector<int> &v){
	os<<"[ ";
	for(int i=0; i<v.size(); i++){
		os<<v[i]<<" ";
	}
	os<<"] ";
	return os;
}

int main()
{
	std::string infile1 = "input1.txt"; // name of input file 1
	std::string infile2 = "input2.txt"; // name of input file 2
	std::string outfile = "output.txt"; // name of output file
	std::vector<int> v;
	NS1::read(v, infile1); // use namespace NS1
	NS2::read(v, infile2); // use namespace NS2
	NS1::print(v, outfile); // use namespace NS1
	NS2::print(v, outfile); // use namespace NS2
	std::cout << v << std::endl; // overload operator <<
	return 0;
}
