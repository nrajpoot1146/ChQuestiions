#include <iostream>
#include <string>
#include "ArrayStack.h"
using namespace std;
class Car{
public:
    string plateNo;
    static int _count;
    Car(string plateNo): plateNo(plateNo){

    }
    Car(){
    }
};
int Car::_count = 0;

class Garage{
    ArrayStack<Car> Lane1, Lane2, Street;
public:
    Garage(){

    }

    void Arrival(string plateNo){
        Car temp(plateNo);
        this->Lane1.push(temp);
        cout<<"Car with plate "<<plateNo<<" has arrived and was parked in lane 1."<<endl;
    }

    void Departure(string plateNo){
        while(!this->Lane1.isEmpty()){
            if(plateNo == this->Lane1.peek().plateNo){
                this->Lane1.pop();
                break;
            }
            this->MoveCars();
        }
        this->Lane1 = this->Lane2;
        cout<<"Car with plate " <<plateNo<< " has departed from lane1 and was moved " <<Car::_count<<" times(s)"<<endl;
        Car::_count++;
    }

    void MoveCars(){
        Car temp = this->Lane1.peek();
        this->Lane2.push(temp);
        this->Lane1.pop();
    }

    void ClearStreet(){
        while(!this->Street.isEmpty())
            this->Street.pop();
    }

    bool search(string plateNo){
        while(!this->Lane1.isEmpty()){
            if(plateNo == this->Lane1.peek().plateNo){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Garage garage;
    garage.Arrival("123xyz");
    garage.Arrival("345abc");
    garage.Departure("123xyz");
    garage.Departure("345abc");
}
