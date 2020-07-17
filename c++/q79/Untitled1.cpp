#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

//global constant
const int MAX = 15;    //maximum number of players on team


//structure PlayerInfo - data for one player
struct PlayerInfo
{
   string name;
   int playerNumber;
   int numHits;
   int numOuts;
   int timesAtBat;
   int numWalks = 0;
   double batAvg = 0;
};

// TODO: Write functions here

/**
* read roster data from file and store into array of player info
*/
void readFile(PlayerInfo players[], int &playerCount){
	ifstream fin;
	string filename;
	cout<<"Enter file name: ";
	cin>>filename;
	fin.open(filename.c_str()); // open input file
	
	while (!fin.good()){
		cout<<"Error: invalid filenamme!\n";	
		cout<<"Enter file name: ";
		cin>>filename;
		fin.open(filename.c_str()); // open input file
	}

	while(fin){
		string line = "";
		getline(fin, line); // read player name
//		cout<<line;
		
		if(line == ""){
			break;
		}
		
		if (playerCount == 15){
			cout<<"***Too many players in file.\n";
			return;
		}
		
		players[playerCount].name = line; // set player name
		
		getline(fin, line); // read player info
		stringstream ss;
		
		ss<<line.substr(0, line.find(' '));
		ss>>players[playerCount].playerNumber; // set player number
		ss.clear();
		
		line = line.substr(line.find(' ')+1);
		ss<<line.substr(0, line.find(' '));
		ss>> players[playerCount].numHits; // set player hits
		ss.clear();
		
		line = line.substr(line.find(' ')+1);
		ss<<line.substr(0, line.find(' '));
		ss>>players[playerCount].numOuts; // set player outs
		ss.clear();
		
		line = line.substr(line.find(' ')+1);
		ss<<line;
		ss>>players[playerCount].timesAtBat; // set times at bat
		playerCount++;
		
	}

	fin.close();
}

/**
* display single player info
*/
void display(const PlayerInfo &player){
	
	cout<<left<<setw(22);
	cout<<player.name; // display player name
	
	cout<<setw(12);
	cout<<player.playerNumber; // display player number
	
	cout<<setw(12);
	cout<<player.numHits; // display player hits
	
	cout<<setw(12);
	cout<<player.numOuts; // display player outs
	
	cout<<setw(12);
	cout<<player.timesAtBat; // display player bats
	
	cout<<setw(10);
	cout<<player.numWalks; // display player walks
	
	cout<<fixed<<setprecision(3);
	cout<<player.batAvg; // display player bat avg
}

// display player with batAvg is greater than given bat avg
void displayBatAvg(PlayerInfo players[],const int playerCount){
	double th;
	cout<<"Enter batting average: \n";
	cin>>th;
	cout<<"PLAYERS ABOVE "<<th<<endl;
	
	cout<<"Player Name         Number       Hits        Outs       AtBats      Walks      BatAvg\n";
	cout<<"_____________________________________________________________________________________\n";
	
	for (int i = 0; i<playerCount; i++){
		if (players[i].batAvg >= th){
			display(players[i]);
			cout<<endl;
		}
	}	
}

// display full team 
void displayTeam(PlayerInfo players[],const int playerCount){
	cout<<"ROSTER of "<<playerCount<<" PLAYERS\n";
	cout<<"Player Name         Number       Hits        Outs       AtBats      Walks      BatAvg\n";
	cout<<"_____________________________________________________________________________________\n";
	
	for (int i = 0; i<playerCount; i++){
		display(players[i]);
		cout<<endl;
	}
}

// calculate walk and average bat
void calcBatAvg(PlayerInfo players[], int &playerCount){
	for (int i=0; i<playerCount; i++){
		players[i].numWalks = players[i].timesAtBat - (players[i].numHits + players[i].numOuts);
		players[i].batAvg = ((double)players[i].numHits) / (players[i].timesAtBat - players[i].numWalks);
	}
}

// add player to player list
void addPlayer(PlayerInfo players[], int &playerCount){
	if (playerCount >= 15){
		cout<<"Too many players, player cannot be added.\n";
		return;
	}
	
	cin.ignore();
	cout<<"Enter new player's name: \n";
	getline(cin,players[playerCount].name); // read player name
	
	cout<<"Enter new player's number: \n";
	cin>>players[playerCount].playerNumber; // read player number
	
	cout<<"Enter new player's hits: \n";
	cin>>players[playerCount].numHits; // read player hits
	
	cout<<"Enter new player's outs: \n";
	cin>>players[playerCount].numOuts; // read player outs
	
	cout<<"Enter new player's at bats: \n";
	cin>>players[playerCount].timesAtBat; // read player bats
	
	playerCount++;
	
	calcBatAvg(players, playerCount);
}

// display menu
void menu(){
	cout<<"MENU"<<endl;
	cout<<"a - Add player\n";
	cout<<"b - Display playerrs above batting average\n";
	cout<<"d - Display  full roster\n";
	cout<<"q - Quit\n\n";
	
	cout<<"Choose an optionL: ";
}

int main()
{

   PlayerInfo players[25];           // array to hold PlayerInfo
   int playerCount = 0;           // how many players in array

	// read player info from file
	readFile(players, playerCount);
	
	// calculate walk and bat average
	calcBatAvg(players, playerCount);
	
	
	// display menu, loop until user wants to quit
	while (true){
		menu();
		
		char c;
		cin>>c;
		
		if (c == 'q'){
			break;
		}
		
		switch (c){
			case 'a':
				addPlayer(players, playerCount);
				break;
			case 'b':
				displayBatAvg(players, playerCount);
				break;
			case 'd':
				displayTeam(players, playerCount);
				break;
			default:
				cout<<"Choose valid option!\n";
		}
		
		cout<<endl;
	}
}
