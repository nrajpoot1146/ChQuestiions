#include <vector>
#include <iostream>
using namespace std;

class Actor
{
public:
	string actName;
	bool living;
	double salLastYear;
};

class Movie {
public:
	int leadActorIdx;
	int yrReleased;
	string title;
	vector<Actor*>* actors;
	Movie() :actors(NULL), yrReleased(0), leadActorIdx(-1) {}
};

vector < Movie* >* getShows() {
	vector < Movie* >* ms = new vector < Movie* >;
	
	Movie* m = new Movie;
	m[0].title = "Star Wars";
	m[0].yrReleased = 1976;
	m[0].leadActorIdx = 0;
	Actor* a = new Actor;
	m[0].actors = new vector < Actor* >;
	m[0].actors[0].push_back(a);
	a[0].actName = "Mark H.";
	a[0].salLastYear = 773612.98;
	a[0].living = true;
	ms[0].push_back(m);
	
	a = new Actor;
	m[0].actors[0].push_back(a);
	a[0].actName = "Carrie F.";
	a[0].salLastYear = 3616.9;
	a[0].living = false;
	a = new Actor;
	m[0].actors[0].push_back(a);
	a[0].actName = "Harrison F.";
	a[0].salLastYear = 4713616.9;
	a[0].living = true;
	
	m = new Movie;
	m[0].actors = new vector < Actor* >;
	ms[0].push_back(m);
	m[0].title = "Midnite Run";
	m[0].yrReleased = 1991;
	m[0].leadActorIdx = 1;
	a = new Actor;
	m[0].actors[0].push_back(a);
	a[0].actName = "Charles G.";
	a[0].salLastYear = 36616.19;
	a[0].living = true;
	a = new Actor;
	m[0].actors[0].push_back(a);
	a[0].actName = "Bobby D.";
	a[0].salLastYear = 2336616.19;
	a[0].living = true;
	
	m = new Movie;
	ms[0].push_back(m);
	m[0].title = "Life on the Serengheti";
	m[0].yrReleased = 2002;
	
	m = new Movie;
	m[0].actors = new vector < Actor* >;
	ms[0].push_back(m);
	m[0].title = "Othello";
	m[0].yrReleased = 1952;
	m[0].leadActorIdx = 1;
	a = new Actor;
	m[0].actors[0].push_back(a);
	a[0].actName = "Dick B.";
	a[0].salLastYear = 0;
	a[0].living = false;
	a = new Actor;
	m[0].actors[0].push_back(a);
	a[0].actName = "Liz T.";
	a[0].salLastYear = 20.01;
	a[0].living = false;
	
	m = new Movie;
	ms[0].push_back(m);
	m[0].title = "No Man Show";
	m[0].yrReleased = 2018;
	
	m = new Movie;
	m[0].actors = new vector < Actor* >;
	ms[0].push_back(m);
	m[0].title = "1 woman show";
	m[0].yrReleased = 2018;
	a = new Actor;
	m[0].actors[0].push_back(a);
	a[0].actName = "Bea B.";
	a[0].salLastYear = 299310.01;
	a[0].living = true;
	m[0].leadActorIdx = 0;
	
	m = new Movie;
	m[0].actors = new vector < Actor* >;
	ms[0].push_back(m);
	m[0].title = "Ironman";
	m[0].yrReleased = 2010;
	a = new Actor;
	m[0].actors[0].push_back(a);
	a[0].actName = "Don C.";
	a[0].salLastYear = 1291119.01;
	a[0].living = true;
	m[0].leadActorIdx = 1;
	a = new Actor;
	m[0].actors[0].push_back(a);
	a[0].actName = "Downey Jr.";
	a[0].salLastYear = 10291119;
	a[0].living = true;
	a = new Actor;
	m[0].actors[0].push_back(a);
	a[0].actName = "Gweneth P.";
	a[0].salLastYear = 391220;
	a[0].living = true;
	
	m = new Movie;
	m[0].actors = new vector < Actor* >;
	ms[0].push_back(m);
	m[0].title = "Disorderlies";
	m[0].yrReleased = 1990;
	a = new Actor;
	m[0].actors[0].push_back(a);
	a[0].actName = "The Fatboys";
	a[0].salLastYear = 20119.39;
	a[0].living = true;
	m[0].leadActorIdx = 0;
	
	m = new Movie;
	m[0].actors = new vector < Actor* >;
	ms[0].push_back(m);
	m[0].title = "Mortal Kombat";
	m[0].yrReleased = 2014;
	
	m = new Movie;
	m[0].actors = new vector < Actor* >;
	ms[0].push_back(m);
	m[0].title = "Rolling Ball";
	m[0].yrReleased = 2000;
	
	m = new Movie;
	m[0].actors =
	new vector < Actor* >;
	ms[0].push_back(m);
	m[0].title = "Dr. Strangelove";
	m[0].yrReleased = 1963;
	m[0].leadActorIdx = 2;
	a = new Actor;
	m[0].actors = new vector < Actor* >;
	m[0].actors[0].push_back(a);
	a[0].actName = "JE Jones";
	a[0].salLastYear = 742512.0;
	a[0].living = true;
	a = new Actor;
	m[0].actors[0].push_back(a);
	a[0].actName = "George CS.";
	a[0].salLastYear = 62212.0;
	a[0].living = true;
	a = new Actor;
	m[0].actors[0].push_back(a);
	a[0].actName = "Peter S.";
	a[0].salLastYear = 0.0;
	a[0].living = false;
	a = new Actor;
	m[0].actors[0].push_back(a);
	a[0].actName = "S. Pickens";
	a[0].salLastYear = 10.0;
	a[0].living = false;
	return ms;
}

void highestPaid(vector<Movie*>* ms, double& highest_salary, string& name) {
	highest_salary = 0.0;
	for (int i = 0; i < ms->size(); i++) {
		//for (int j = 0; j < ms[i]->ac; j++) {
			for (int k = 0; k < ms->at(i)->actors->size(); k++) {
				if (ms[i][0]->actors->at(k)->salLastYear > highest_salary) {
					highest_salary = ms->at(i)->actors->at(k)->salLastYear;
					name = ms->at(i)->actors->at(k)->actName;
				}
			}
		//}
	}
}

void show2000Shows(vector<Movie*>* ms) {
int line_number = 1;
for (int i = 0; i < ms->size(); i++) {
for (int j = 0; j < ms[i].size(); j++) {
if (ms[i][j]->yrReleased < 2000) {
if (ms[i][j].actors != NULL && ms[i][j].leadActorIdx != -1)
cout << line_number << ". " << ms[i][j].title << " has " << ms[i][j].actors.size() << " actors. The " << ms[i][j].actors[ms[i][j].leadActorIdx].actName << " is lead actor." << endl;
else
cout << line_number << ". " << ms[i][j].title << " has " << ms[i][j].actors.size() << " actors. No lead actor." << endl;
line_number++;
}
}
}
}

int getNoActorsCount(vector<Movie*>* ms) {
int noActorsCount = 0;
for (int i = 0; i < ms.size(); i++) {
for (int j = 0; j < ms[i].size(); j++) {
if (ms[i][j].actors == NULL || ms[i][j].actors.size() == 0)
noActorsCount++;
}
}
return noActorsCount;
}

int actorsWeLost(vector<Movie*>* ms) {
int actorsWeLostCount = 0;
for (int i = 0; i < ms.size(); i++) {
for (int j = 0; j < ms[i].size(); j++) {
for (int k = 0; k < ms[i][j].actors.size(); k++) {
if (!ms[i][j].actors[k].living)
actorsWeLostCount++;
}
}
}
return actorsWeLostCount;
}


int main() {
	vector<Movie*>* movies = getShows();
	show2000Shows(movies);
	int noActorsCount = getNoActorsCount(movies);
	cout << "No Actors Count is: " << noActorsCount << endl;
	
	int actorsWeLostCount = actorsWeLost(movies);
	cout << "Actors we lost count is: " << actorsWeLostCount << endl;
	
	double highestSalary = 0.0;
	string name;
	
	highestPaid(movies, highestSalary, name);
	
	cout << "Highest Salary is " << highestSalary << endl;
	cout << "The name of the actor is " << name << endl;
	
	return 0;

}
