#include<iostream>
#include<string>
#include "ListArray.cpp"


int main(){
	char cmd;
	ListArray listArray;
	while(true){
		cout<<"Command: ";
		cin>>cmd;
		
		if(cmd == 'H'){
			cout<<"Commands:"<<endl;
			cout<<"H\t: Help (displays this message)"<<endl;
			cout<<"+x\t: Insert x after the cursor"<<endl;
			cout<<"-\t: Remove the data marked by the cursor"<<endl;
			cout<<"=x\t: Replace the data item marked by the cursor with x"<<endl;
			cout<<"@\t: Display the dataitm marked by the cursor"<<endl;
			cout<<"<\t: Go to the begnning of the list"<<endl;
			cout<<">\t: Go to the end of the list"<<endl;
			cout<<"N\t: Go to the next data item"<<endl;
			cout<<"P\t: Goto the prior data item"<<endl;
			cout<<"C\t: Clear the list"<<endl;
			cout<<"E\t: Empty list?"<<endl;
			cout<<"F\t: Full list?"<<endl;
			cout<<"!\t: Test copy constructor"<<endl;
			cout<<"#\t: Test assignment operator"<<endl;
			cout<<"Mn\t: Move data item marked by cursor to pos. n"<<endl;
			cout<<"?x\t: Search rest of list for x"<<endl;
			cout<<"Q\t: Quit the test program"<<endl;
			cout<<endl;
		}else if(cmd == '+'){
			//insert x after the cursor
			int x;
			cin>>x;
			cout<<"insert "<<x<<endl;
			listArray.insert(x);
			listArray.showStructure();
		}else if(cmd == '-'){
			//remove from the cursur
			cout<<"Remove the data item marked by the cursor"<<endl;
			listArray.remove();
			listArray.showStructure();
		}else if(cmd == '='){
			//replace the data item marked by cursor with x
			int x;
			cin>>x;
			cout<<"Replace the data item marked by the cursor with "<<x<<endl;
			listArray.replace(x);
			listArray.showStructure();
		}else if(cmd == '@'){
			//show list structure
			listArray.showStructure();
		}else if(cmd == '>'){
			//move cursor at the end 
			cout<<"cursor moved at the end"<<endl;
			listArray.gotoEnd();
			listArray.showStructure();
		}else if(cmd == '<'){
			//move cursor at the beginning
			cout<<"cursor moved at the beginning"<<endl;
			listArray.gotoBeginning();
			listArray.showStructure();
		}else if(cmd == 'N' || cmd=='n'){
			//move cursor to next posion 
			cout<<"Gt to the next dataitem "<<endl;
			listArray.gotoNext();
			listArray.showStructure();
		}else if(cmd == 'P' || cmd =='p'){
			//move cursor to prior posion
			cout<<"Go to the previous data item  "<<endl;
			listArray.gotoPrior();
			listArray.showStructure();
		}else if(cmd == 'C' || cmd == 'c'){
			cout<<"list cleared";
			listArray.clear();
			listArray.showStructure();
		}else if(cmd == 'E' || cmd = 'e'){
			if(listArray.isEmpty()){
				cout<<"List is empty"<<endl;
			}else{
				cout<<"List is not empty"<<endl;
			}
			listArray.showStructure();
		}else if(cmd == 'F' || cmd == 'f'){
			if(listArray.isFull()){
				cout<<"List is full"<<endl;
			}else{
				cout<<"List is not full"<<endl;
			}
			listArray.showStructure();
		}else if(cmd == '!'){
			cout<<"look at the two list below and decide whether they are equivalent"<<endl;
			ListArray list2(listArray);
			cout<<"List 1:";
			listArray.showStructure();
			cout<<"List 2:";
			list2.showStructure();
		}else if(cmd == '#'){
			cout<<"look at the two list below and decide whether they are equivalent"<<endl;
			ListArray list2 = listArray;
			cout<<"List 1:";
			listArray.showStructure();
			cout<<"List 2:";
			list2.showStructure();
		}else if(cmd == 'M' || cmd=='m'){
			int x;
			cin>>x;
			cout<<"Move the data item marked by the cursor to postion "<<x<<endl;
			listArray.moveToNth(x);
			listArray.showStructure();
		}else if(cmd == '?'){
			int x;
			cin>>x;
			if(listArray.find(x)){
				cout<<"found"<<endl;
			}else{
				cout<<"not found"<<endl;
			}
			listArray.showStructure();
		}else if(cmd == 'Q'){
			break;
		}
		
	}
	
}
