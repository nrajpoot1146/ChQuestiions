#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream ifs; // input stream for plain file
	ofstream ofs; // output stream for coded file
	string inputFile = "plain.txt"; // plain file name
	string outputFile = "coded.txt"; // coded file name
	
	ifs.open(inputFile.c_str()); // open file input stream
	if (!ifs.good()){ // check input stream file is open or not
		cout<<"Input file does not exist."<<endl;
		return 0;
	}
	ofs.open(outputFile.c_str()); // open output stream
	string line = "";
	string coded = "";
	while (true){
		getline(ifs, line); // read line from input file
		if (ifs.eof()){ // check whether it is end of file or not
			break;
		}
		coded = "";
		
		// coded line from a plain line
		for (int i=0; i<line.length(); i++){
			coded += (char)(((int)line[i] + 6) % 256); // get coded character
		}
		
		// write coded line to output file
		ofs<<coded<<endl<<flush;
	}
	
	cout<<"plain file coded successfully."<<endl;
	return 0;
}
