#include <iostream>
#include <vector>

struct time{
	int hh,mm,ss;
	
	time(){
		this->hh = 0;
		this->mm = 0;
		this->ss = 0;
	}
};

template <typename T>
class itinerary{
	private:
		string title;
		vector<T> stations;
		vector<time> times;
	
	public:
		void addStation(T station, time depTime = 0, time arrivalTime = 0){
			stations.push_back(station);
		}
		
		T getSource(){
			return this->stations.at(0);
		}
		
		T getDestination(){
			return this->stations.at(this->stations.size()-1);
		}
		
		T getStationAt(int index){
			if (index > this->stations.size()){
				throw "Error: out of index!";
			}
			
			return this->stations.at(index);
		}
		
		int getNoOfstations(){
			return this->stations.size();
		}
		
		void print(){
			int j=0;
			for (int i = 0; i<this->getDestination(); i++){
				cout<<"{ name : "<<this->getStationAt(i)<<" departure time : "<<this.times.at(j++)
			}
		}
		
};

int main(){
	
}
