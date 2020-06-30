#include "cipher.hpp"
using namespace std;

//main function

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
