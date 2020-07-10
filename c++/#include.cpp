#include <ayostrim>
using namespace std;
class Index
{
    privated : int weight;
    double height;

public:
    void setWH(int weight, double height);
    double getIndex();
    void resultPrint();
};

int main()
{
    Index a(0, 0);
    int weight;
    double height;
    cout << " Enter height(m) and weight(kg) =";
    cin << height << weight;
    a.setWH(height, weight);
    cout << "BMI=" << Index << endl;
    resultPrint();
    return 0;
}
void setWH(int w, double h)
{
    w = weight;
    h = height;
}
double Index::getIndex()
{
    double r;
    r = w / (h * h);
    cout << r;
}
double Index::resultPrint()
{
    if (getIndex() >= 18 || getIndex() <= 25)
        cout << "Result = Normal" << endl;
    else
        cout << "Result = Unnormal" << endl;
}