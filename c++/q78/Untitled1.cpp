/**********************************************************/

#include <iostream> 						// needed for I/O
#include <iomanip>
#include <cmath>


/***************************************
* pre-processor
***************************************/
#define PI 3.14159
using namespace std;

/***************************************
* 		function prototypes
***************************************/
float areaCircle (float radiusIn);
float circumCircle(float radiusIn);
float areaSphere(float radiusIn);
float circumSphere(float radiusIn);
float volumeSphere(float radiusIn);
float areaCylinder(float radiusIn, float heightIn);
float volumeCylinder(float radiusIn, float heightIn);
float volumeCone(float radiusIn, float heightIn);

/*******************************************
* main()	the function ttthat executes
*******************************************/
int main()
{
	/************************************
	* 	local variables					*
	*************************************/

	float radiusIn;				// variable input for radius
	float heightIn;				// variable input for height
	float area;
	float circum;
	float volume;
	
	// Questions
	cout<<"Enter the raius of the \n";
	cout<<"     circle, cone, sphere, or cylinder: ";
	cin>>radiusIn;
	cout<<"     Enter the height of the cylinder or cone: ";
	cin>>heightIn;
	
	/*********************
	* Function & Display *
	**********************/
	cout <<setprecision((2))<<fixed<<"\n";
	cout<<"radius is "<<radiusIn<<"\n";
	cout<<"height is "<<heightIn<<"\n\n\n";
	
	area = areaCircle(radiusIn);
	cout << "area of the circle is " <<setw(5)<<area<<"\n";
	
	circum = circumCircle(radiusIn);
	cout<<"circumference of the circle is "<<setw(5)<<circum<<"\n\n";
	
	area = areaSphere(radiusIn);
	cout<< "area of the sphere is "<< setw(5)<<area<<"\n";
	
	circum = circumSphere(radiusIn);
	cout<< "circumference of the sphere is "<<setw(5)<<circum<<"\n";
	
	volume = volumeSphere(radiusIn);
	cout << "volume of sphere is "<<setw(5)<<volume<<"\n\n";
	
	area = areaCylinder(radiusIn, heightIn);
	cout<<"area of cylinder is "<<setw(5)<<area<<"\n";
	
	volume = volumeCylinder(radiusIn, heightIn);
	cout<<"volume of the cylinder is "<<setw(5) <<volume<<"\n\n";
	
	volume = volumeCone(radiusIn, heightIn);
	cout<<"volume of the cone is "<<setw(5)<<volume<<"\n\n";
	
	system("pause");
	return 0;
}

/*****************************************
* given radiu, calculate circle's area
*****************************************/
float areaCircle(float radiusIn){
	float area;
	area = PI * (radiusIn * radiusIn);
	return area;
}

/**************************************************
* given radiu, calculate circle's circumference
**************************************************/
float circumCircle(float radiusIn){
	float circum;
	circum = PI * radiusIn * 2;
	return circum;
}

/*****************************************
* given radiu, calculate sphere's area
*****************************************/
float areaSphere(float radiusIn){
	float area;
//	old : 4 * PI * (radiusIn * radiusIn);
	area = 4 * areaCircle(radiusIn);
	return area;
}

/*************************************************
* given radiu, calculate sphere's circumference
**************************************************/
float circumSphere(float radiusIn){
	float circum;
//	old : circum = PI * radiusIn * 2;
	circum = circumCircle(radiusIn);
	return circum;
}

/*****************************************
* given radius and height,
* calculate sphere's volume
*****************************************/
float volumeSphere(float radiusIn){
	float volume;
//	old : volume = 4.0 / 3.0 * PI * (radiusIn * radiusIn *radiusIn);
	volume = (4.0 / 3.0) * areaCircle(radiusIn) * radiusIn;
	return volume;
}

/*****************************************
* given radius and height,
* calculate cylinder's surface area
*****************************************/
float areaCylinder(float radiusIn, float heightIn){
	float area;
//	old : area = ((2 * PI * radiusIn * radiusIn)) + ((heightIn * PI * radiusIn *2);
	area = ((2 * areaCircle(radiusIn)) + (heightIn * circumCircle(radiusIn)));
	return area;
}

/*****************************************
* given radius and height,
* calculate cylinder's volume
*****************************************/
float volumeCylinder(float radiusIn, float heightIn){
	float volume;
//	old: volume = PI * (radiusIn * radiusIn) * heightIn;
	volume = areaCircle(radiusIn) * heightIn;
	return volume;	
}

/*****************************************
* given radius and height,
* calculate cone's volume
*****************************************/
float volumeCone(float radiusIn, float heightIn){
	float volume;
//	old : volume = ((PI * radiusIn * radiusIn * heightIn) * (0.3333333333));
	volume = volumeCylinder(radiusIn, heightIn) * (0.33333333333);
	return volume;
}

