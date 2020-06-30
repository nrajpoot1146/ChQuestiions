#include<iostream>
using namespace std;


int checked[8] = {0};
string currectWord ="SPACEMAN";
string guessC = "_ _ _ _ _ _ _ _"; // guessed correct word
string guessI = "_ _ _ _ _ _ _ _"; // guessed incorrect word
int incorrectCount = 0;
int correctCount = 0;

// function to reset all variable to their default value
void initializ(){
	for(int i=0; i<8; i++){
		checked[i] = 0;
	}
	guessC = "_ _ _ _ _ _ _ _";
	guessI = "_ _ _ _ _ _ _ _";
	incorrectCount = 0;
	correctCount = 0;
}

//function to draw alien ship according to incorrect letter count
void drawShip(int n){
	if(n==1){
		cout<<endl<<endl<<endl;
		cout<<"    _____________________"<<endl;
		cout<<"    \\___________________/"<<endl;
	}else if(n==2){
		cout<<endl<<endl<<endl;
		cout<<"    ___________________"<<endl;
		cout<<"    \\__0__0__0__0__0__/"<<endl;
	}else if(n==3){
		cout<<endl<<endl<<endl;
		cout<<"    ___________________"<<endl;
		cout<<"    \\__0__0__0__0__0__/"<<endl;
		cout<<"      \\_____________/"<<endl;
	}else if(n==4){
		cout<<endl<<endl<<endl;
		cout<<"    ___________________"<<endl;
		cout<<"    \\__0__0__0__0__0__/"<<endl;
		cout<<"      \\_|_|_|_|_|_|_/"<<endl;
	}else if(n==5){
		cout<<endl<<endl<<endl;
		cout<<"    ____/__________\\___"<<endl;
		cout<<"    \\__0__0__0__0__0__/"<<endl;
		cout<<"      \\_|_|_|_|_|_|_/"<<endl;
	}else if(n==6){
		cout<<endl<<endl<<endl;
		cout<<"         ..             "<<endl;
		cout<<"    ____/__________\\___"<<endl;
		cout<<"    \\__0__0__0__0__0__/"<<endl;
		cout<<"      \\_|_|_|_|_|_|_/"<<endl;
	}else if(n==7){
		cout<<endl<<endl<<endl;
		cout<<"         ..      ..     "<<endl;
		cout<<"    ____/__________\\___"<<endl;
		cout<<"    \\__0__0__0__0__0__/"<<endl;
		cout<<"      \\_|_|_|_|_|_|_/"<<endl;
	}else if(n==8){
		cout<<endl<<endl;
		cout<<"           ......       "<<endl;
		cout<<"         ..      ..     "<<endl;
		cout<<"    ____/__________\\___"<<endl;
		cout<<"    \\__0__0__0__0__0__/"<<endl;
		cout<<"      \\_|_|_|_|_|_|_/"<<endl;
	}
	else if(n==9){
		cout<<endl<<endl;
		cout<<"           ......      "<<endl;
		cout<<"         .. \\_/  ..     "<<endl;
		cout<<"    ____/___(\")____\\___"<<endl;
		cout<<"    \\__0__0__0__0__0__/"<<endl;
		cout<<"      \\_|_|_|_|_|_|_/"<<endl;
	}
	
}


// draw alien
void drawAlien(int n){
	cout<<"+----------------------------------------------------------+"<<endl;
	drawShip(n);
	if(n!=9){
		cout<<"                              \\_/                           "<<endl;
		cout<<"                              (\")                           "<<endl;
		cout<<"                            ---+---                         "<<endl;
		cout<<"                             _/ \\_                          "<<endl;
	}
	cout<<"+----------------------------------------------------------+"<<endl;
}

// check guessed letter is correct or not
// if gussed letter is correct then function return index of guessed letter in correct word otherwise return -1
int isCorrect(char gC){
	for (int i=0; i<currectWord.length(); i++){
		if(currectWord[i] == gC && checked[i] == 0){
			checked[i] = 1;
			return i;
		}
	}
	return -1;
}

// check guessed letter is a alphabet or not if it is not a alphabet then return false otherwise return true
bool isChar(char c){
	if((c>='A' && c<='Z') || ( c>='a' && c<='z' )){
		return true;
	}
	return false;
}

// read input from user side
char getUserInput(){
	char c;
	cout<<"Earth leader? ";
	cin>>c;
	return c;
}

int main(){
	cout<<"      -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;
	cout<<"         Welcome to SPACEMAN, a word-guessing game!  "<<endl;
	cout<<"      -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;
	cout<<endl;
	cout<<"    Zuurp, an alien, has crasehd on planet Earth! Zuurp"<<endl;
	cout<<"      mistakes you for Earth's leader and demands you"<<endl;
	cout<<"   guess their secret word, one letter at a time. Zuurp's "<<endl;
	cout<<"   people have been monitoring Earth for years, and hence"<<endl;
	cout<<"           know the English language quite well!"<<endl;
	cout<<endl;
	cout<<"     If you don't guess the word quickly enough, Zuurp"<<endl;
	cout<<"   will rebuild their spaceship and leave, but if you do"<<endl;
	cout<<"  manage to guess Zuurp's secret word then they will stay"<<endl;
	cout<<"  to play again! Beware, Zuurp likes numbers, and will be"<<endl;
	cout<<"             recording your data as you guess!"<<endl;
	
	while(true){
		char gC;
		drawAlien(incorrectCount);
		cout<<"Zuurp counts "<<incorrectCount<<" incorrect guesses... [ "<<guessI<<" ]"<<endl;
		
		if(incorrectCount < 9){
			cout<<"Zuurp's secret word: "<<guessC<<endl;
			gC = getUserInput();
			while(!isChar(gC)){
				cout<<"Zuurp says, \"Qzwopp! "<<gC<<" is not a letter!\""<<endl;
				gC = getUserInput();
			}
			
			int index = isCorrect(gC);
			if(index > -1){
				guessC[index + index] = gC;
				correctCount++;
			}else{
				guessI[incorrectCount+incorrectCount] = gC;
				incorrectCount++;
			}
		}
		
		// if all guessed letter are correct
		if(correctCount == 8){
			cout<<"      -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;
			cout<<"     Zzoopz!! That means 'well done' on Zuurp's' worls!  "<<endl;
			cout<<"      -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;
			char op;
			cout<<"Zuurp say, \"Do you want to try again?\""<<endl;
			op = getUserInput();
			while(op != 'y' && op != 'Y' && op != 'n' && op != 'N'){
				cout<<"Zuurp demands, \"You must chose 'Y' or 'y' to play!\""<<endl;
				drawAlien(0);
				cout<<"Zuurp say, \"Do you want to try again?\""<<endl;
				op = getUserInput();
			}
			if(op == 'y' || op == 'Y'){
				cout<<endl;
				cout<<"      -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;
				cout<<"       Something went wrong with Zuurp's spaceship... "<<endl;
				cout<<"      Zuurp return to planet Earth to rebuild again..."<<endl;
				cout<<"      -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;
				initializ();
				continue;
			}else{
				break;
			}
		}
		
		// if all guessed letter are incorrect
		if(incorrectCount == 9){
			cout<<"Zuurp says, \"My secret word war..."<<endl;
			for (int i = 0; i<currectWord.length(); i++){
				cout<<currectWord[i]<<" ";
			}
			cout<<endl;
			cout<<"      -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;
			cout<<"                 Zuurp is ready to go home!  "<<endl;
			cout<<"      -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;
			cout<<"Zuurp say, \"Do you want to try again?\""<<endl;
		
			char op;
			op = getUserInput();
			while(op != 'y' && op != 'Y' && op != 'n' && op != 'N'){
				cout<<"Zuurp demands, \"You must chose 'Y' or 'y' to play!\""<<endl;
				drawAlien(0);
				cout<<"Zuurp say, \"Do you want to try again?\""<<endl;
				op = getUserInput();
			}
			if(op == 'y' || op == 'Y'){
				cout<<endl;
				cout<<"      -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;
				cout<<"       Something went wrong with Zuurp's spaceship... "<<endl;
				cout<<"      Zuurp return to planet Earth to rebuild again..."<<endl;
				cout<<"      -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;
				initializ();
				continue;
			}else{
				cout<<endl;
				cout<<"      -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;
				cout<<"        Zuurp left planet Earth for good this time! "<<endl;
				cout<<"      -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;
				cout<<endl;
				cout<<" 0 words fully revealed."<<endl;
				cout<<" 1 words not fully revealed."<<endl;
				cout<<" "<<correctCount<<" letterd correctly guessed."<<endl;
				cout<<" "<<incorrectCount<<" letterd incorrectly guessed."<<endl;
				cout<<"\nBewarre! Zuurp will be reporting this data to their leader! "<<endl;
				cout<<"      -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;
				
				break;
			}
		}
	}
}
