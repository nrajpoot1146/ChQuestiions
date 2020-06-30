#include <iostream>
using namespace std;
class Index
{
    private: // old: privated
	int weight;
    double height;

public:
	Index(int weight, double height){ // old: constructor definition missing
		this->height = height;
		this->weight = weight;
	}
    void setWH(int, double); // old: void setWH(int weight, double height);
    double getIndex(); 
    void resultPrint();
};

int main()
{
    Index a(0, 0);
    int weight;
    double height;
    cout << " Enter height(m) and weight(kg) =";
    cin >> height >> weight; // old: cin << height << weight;
    a.setWH(weight, height); //old: a.setWH(height, weight);
    cout << "BMI = " << a.getIndex() << endl; // old: cout << "BMI=" << Index << endl;
    a.resultPrint(); // old: resultPrint();
    return 0;
}
void Index::setWH(int w, double h) //old: void setWH(int w, double h)
{
    this->weight = w;				//old: w = weight
    this->height = h;				//old: h = height
}
double Index::getIndex()
{
    double r;
    r = this->weight / (this->height * this->height); // old: r = w / (h * h);
    return r; // old cout<< r;
}
void Index::resultPrint()
{
    if (getIndex() >= 18 && getIndex() <= 25) // old: if (getIndex() >= 18 || getIndex() <= 25)
        cout << "Result = Normal" << endl;
    else
        cout << "Result = Unnormal" << endl;
}
