#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

vector<int> permute(vector<int>, vector<int>);
string encrypt(vector<int>s1 , vector<int> t1, string p);
string stringToHex(string str);

int main() {
   	ifstream ifs;
   	ofstream ofs;
   	ifs.open("input.txt"); // open input file
   	ofs.open("output.txt"); // open output file
   	if (!ifs.good()){ // check file is opened or not
   		// if not opened print error message and close the program
   		cout<<"Error: ivalid file name:\n";
   		exit(0);
   	}

   	vector<int> S(256);
   	vector<int> T(256);
   	int key[] = { 1,2,3,6 };
   	int key2[] = { 5,7,8,9 };
   	int tmp = 0;
   
   	for (int i = 0; i < 256;i++) {
    	S[i] = i;
       	T[i] = key[( i % (sizeof(key)/sizeof(*key)) )];
   	}
   	S = permute(S, T);
   	for (int i = 0; i < 256 ;i++) {
       	cout << S[i] << " ";
       	if ((i + 1) % 16 == 0)
           	cout << endl;
   	}
   	cout << endl;
   
   	while (!ifs.eof()) {
	   	string line = "";
		getline (ifs, line); // get line from input file
		if (ifs.eof()){
			// is pointer reached at the end of file or not
			break;
		}
		string encHex = stringToHex(encrypt(S, T, line)); // get encrypted hex value
		ofs<<encHex<<endl; // write encrypted hex value to file
   	}
   	ofs.close(); // close output file
   	ifs.close(); // close input filse
   
   	cout<<endl<<"File sucessfully encypted.";
   	return 0;
}

string stringToHex(string str){
	stringstream ss; // string stream
	for(int i=0; i<str.length(); i++){
		int val = (int)(str[i] & 0xFF); // get integer value for character
		ss<<hex<<val; // convert into hex value and store in string stream object
	}
	ss>>str; // get string from stringstream
	return str; // return hex
}

string encrypt(vector<int>s1, vector<int> t1, string p) {
   int i = 0;
   int j = 0;
   int tmp = 0;
   int k = 0;
   int b;
   int c;
   int * cipher = new int [p.length()];
   string cipherT;
   cout << "Keys Generated for plaintext: ";
   for (int r = 0; r < p.length(); r++) {
       i = (i + 1) % 256;
       j = (j + s1[i]) % 256;
       b = s1[i];
       s1[i] = s1[j];
       s1[j] = b;
       tmp = (s1[i] + s1[j]) % 256;
       k = s1[tmp];
       cout << k << " ";
       c = ((int)p[r] ^ k);
       cipher[r] = c;
       cipherT += (char)cipher[r];
   }
   cout << endl;
   return cipherT;  
}

vector<int> permute(vector<int> s1, vector<int> t1) {
   int j = 0;
   int tmp;
   for (int i = 0; i< 256; i++) {
       j = (j + s1[i] + t1[i]) % 256;
       tmp = s1[i];
       s1[i] = s1[j];
       s1[j] = tmp;
   }
   return s1;
}
