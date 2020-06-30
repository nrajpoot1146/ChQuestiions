#include<iostream>
#include<stdio.h>
#include<string.h>
#include<assert.h>

using namespace std;


int strlen(unsigned char * _str){
	int i=0;
	while(_str[i] != '\0'){
		i++;
	}
	return i;
}

class cipher{
	private:
		char key[8] = {'1','1','1','1','0','0','1','0'};
		unsigned char original[9];
		unsigned char encoded[9];
		unsigned char decoded[9];
	public:
		cipher(){
			
		}
		void getInput(){
			cout<<"Enter your orignal binary string: ";
			cin>>this->original;
			if(strlen(this->original) < 8){
				for(int i= strlen(this->original) ; i<8; i++){
					this->original[i] = 0;
				}
			}else if(strlen(this->original) > 8){
				cout<<"Stack overflow.";
			}
		}
		
		unsigned char cipherWithKey(unsigned char temp[]){
			char encoded[9];
			if(strlen(temp) < 8){
				for(int i= strlen(temp) ; i<8; i++){
					temp = 0;
				}
			}else if(strlen(temp) > 8){
				cout<<"Stack overflow.";
				return '\0';
			}
			
			int i=0;
			for(i=0; i<8 ; i++){
				encoded[i] = ((temp[i] - '0') ^ (this->key[i] - '0')) + '0';
			}
			
		}
		
		void printCipher(const unsigned char &k){
			for(int i=0; i<8; i++){
				cout<< ((k>>i) & 1);
			}
		}
		
		unsigned char stringToBinary(char xx[]){
			int len = strlen(xx);
			char c;
			for(int i=0,k=len-1; i<len; i++,k--){
				c = c | (xx[i]<<k);
				
			}
			return c;
		}
		
		unsigned char scrambler(unsigned char o){
			unsigned shift = 2;
			int m =0x22;
			int t;
			t = ((o >> shift) ^ o) & m;
			o = (o ^ t) ^ (t << shift);
			return o;
		}
		
		unsigned char *getEncoding() const{
			return (unsigned char*)(this->encoded);
		}
		
		unsigned char *getDecoding() const{
			return (unsigned char*)(this->decoded);
		}
		
		bool encoder(){
			int i=0;
			for(i=0; i<8 ; i++){
				this->encoded[i] = ((this->original[i] - '0') ^ (this->key[i] - '0')) + '0';
			}
			if(i == 8){
				this->encoded[8] = '\0';
				return true;
			}
			return false;
		}
		
		bool decoder(){
			int i=0;
			for(i=0; i<8 ; i++){
				this->decoded[i] = ((this->encoded[i] - '0') ^ (this->key[i] - '0')) + '0';
			}
			if(i == 8){
				this->decoded[8] = '\0';
				return true;
			}
			return false;
		}
		
		char *unsig2char(unsigned char k) const{
			return (char*) k;
		}
		
		bool compare(){
			int flag = strcmp((const char*)this->original , (const char* )this->decoded);
			if(flag == 0){
				return true;
			}
			return false;
		}
		
	
};

ostream& operator <<(ostream &output, const cipher &o){
	output<<o.getEncoding()<<endl;
	output<<o.getDecoding()<<endl;
}

int main(){
	cipher c;
	c.getInput();
	assert(c.encoder());
	assert(c.decoder());
	
	cout<<c<<endl;
	
	if(c.compare()){
		cout<<">> Test passed.\n";
	}
	else{
		cout<<">> Test failed.\n";
	}
}
