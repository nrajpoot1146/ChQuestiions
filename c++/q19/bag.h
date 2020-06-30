#ifndef __BAG__
#define __BAG__
#include<vector>
#include<string>
using namespace std;

class Bag{
	private:
		vector<string> items;
	public:
		void push_back(string str);
		
		int size();
		
		string at(int i);
		
		Bag bagUnionWith(Bag bag);
};
#include "bag.cpp"
#endif
