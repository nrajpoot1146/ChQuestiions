#include<iostream>
#include<stdio.h>
#include<string.h>
#include<assert.h>
#define MSG_LENGTH 8
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
       char key[MSG_LENGTH] = {'1','1','1','1','0','0','0','1'};
       unsigned char original[9];
       unsigned char encoded[9];
       unsigned char decoded[9];
   public:
       cipher(){
          
       }
       
       //function to read input from the user
       void getInput(){
           cout<<"Enter your 8bit input string as a pattern of 1`s and 0`s: ";
           cin>>this->original;
           if(strlen(this->original) < 8){
               for(int i= strlen(this->original) ; i<8; i++){
                   this->original[i] = 0;
               }
           }else if(strlen(this->original) > 8){
               cout<<"Stack overflow.";
           }
       }
      
      //get cipher text after performing xor operation
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
      
      //print cipher test
       void printCipher(const unsigned char &k){
           for(int i=0; i<8; i++){
               cout<< ((k>>i) & 1);
           }
       }
      
      //conver a string to binary number
       unsigned char stringToBinary(char xx[]){
           int len = strlen(xx);
           char c;
           for(int i=0,k=len-1; i<len; i++,k--){
               c = c | (xx[i]<<k);
              
           }
           return c;
       }
      
      //get random shift number
       unsigned char scrambler(unsigned char o){
           unsigned shift = 2;
           int m =0x22;
           int t;
           t = ((o >> shift) ^ o) & m;
           o = (o ^ t) ^ (t << shift);
           return o;
       }
      
      //get encoded text
       unsigned char *getEncoding() const{
           return (unsigned char*)(this->encoded);
       }
      
      //get decoded text
       unsigned char *getDecoding() const{
           return (unsigned char*)(this->decoded);
       }
      
      //encoder function
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
      
      //decoder function
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
   output<<endl;
   output<<"Encoded: "<<o.getEncoding()<<endl;
   output<<"Decoded: "<<o.getDecoding()<<endl;
}
