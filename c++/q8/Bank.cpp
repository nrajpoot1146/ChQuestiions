#ifndef bank_cpp
#define bank_cpp

#include"Account.cpp"
#include<map>
using namespace std;
class Bank{
	private:
		string name;
		int routingnum;
		int count;
		map<int, Account*> accounts;
	public:
		Bank(): name(""), routingnum(0), count(0){
			
		}
		
		Bank(string name, int routingNum):name(name), routingnum(routingNum),count(0){
			
		}
		
		int createAccount(string n, string address, float balance){
			int acctNum = ++count;
			Account *ac = new Account(acctNum, balance, n, address);
			this->accounts[acctNum] = ac;
			return acctNum;
		}
		
		bool deleteAccount(int account){
			if(this->accounts.find(account) == this->accounts.end()){
				return false;
			}
			this->accounts.erase(account);
			return true;
		}
		
		void setName(string n){
			this->name = n;
		}
		
		string getname(){
			return this->name;
		}
		
		void setroutingnum(int num){
			this->routingnum = num;
		}
		
		int getroutingnum(){
			return this->routingnum;
		}
		
		map<int, Account*> getAccounts(){
			return this->accounts;
		}
};

#endif
