#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DOORS_AREA 21
#define WINDOWS_AREA 12

#define SPLASH_SQFT 550
#define CHANGE_SQFT 400
#define COVER_SQFT 350

#define PRICE_SPLASH 19.99
#define PRICE_CHANGE 29.99
#define PRICE_COVER 39.99

void displayIntroduction();
int calculateSqFootage();
int calculateDoorsWindows();
int calculateGallons(int gallons, int coat, char code);
float calculateCost(int gallons, char code);
void displayTermination();

int main(int argc, char **argv)
{
    displayIntroduction();
    int grossSqFootage = calculateSqFootage();
    int grossDoorsWindows = calculateDoorsWindows();
    int wallSpace = grossSqFootage - grossDoorsWindows;
    printf("\n\nThis results in %5d square feet to be painted.", wallSpace);
    printf("\n------------------------------------------------------------");

    int totalGallons = calculateGallons();
    double totalCost = calculateCost() * totalGallons;
    printf("\nThe cost of \"Splash-of-color\":");
    printf("\nfor one coat: %2d gallons --> %5.2f", totalGallons, totalCost);
    printf("\nfor two coats: %2d gallons --> %5.2f", totalGallons, totalCost);
    printf("\nfor three coats: %2d gallons --> %5.2f", totalGallons, totalCost);
    printf("\n------------------------------------------------------------");
    printf("\nThe cost of \"Change-the-mood\":");
    printf("\nfor one coat: %2d gallons --> %5.2f", totalGallons, totalCost);
    printf("\nfor two coats: %2d gallons --> %5.2f", totalGallons, totalCost);
    printf("\n------------------------------------------------------------");
    printf("\nThe cost of \"Cover-all-sins\":");
    printf("\nfor one coat: %2d gallons --> %5.2f", totalGallons, totalCost);
    printf("\n************************************************************");

    displayTermination();
    return (EXIT_SUCCESS);
}

void displayIntroduction()
{
    printf("************************************************************");
    printf("\n************************************************************");
    printf("\nThis is a program that calculates the total cost of");
    printf("\nwall space to be painted.");
    printf("\nThe user will be required to enter the dimensions of a");
    printf("\nroom, including the number of doors and windows needed.");
    printf("\nThe program must calculate the number of gallons to be used");
    printf("\nand the cost for every gallon used per coat of paint.");
}

float calculateCost(int gallons, char code)
{
    float perGal;
    switch (code)
    {
    case 'a':
        perGal = PRICE_SPLASH;
        break;
    case 'b':
        perGal = PRICE_CHANGE;
        break;
    case 'c':
        perGal = PRICE_COVER;
        break;
    }
    return perGal * gallons;
}

int calculateGallons(int gallons, int coat, char code)
{
    int wallSpace;
    float totalGallon;
    switch (code)
    {
    case 'a':
        totalGallon = wallSpace % SPLASH_SQFT;
        break;
    case 'b':
        totalGallon = wallSpace % CHANGE_SQFT;
        break;
    case 'c':
        totalGallon = wallSpace % COVER_SQFT;
        break;
    }
    return round(totalGallon);
}

int calculateSqFootage()
{
    printf("\n************************************************************");
    printf("\nPlease enter the length, width and height of the room to");
    printf("\nbe painted.");
    printf("\nFor example, if your room is ");
    printf("\n 17 feet long,");
    printf("\n 14 feet wide and");
    printf("\n 6 feet high,");
    printf("\nEnter 17 14 6");
    printf("\nAll numbers should be positive \n--> ");

    int length, width, height;
    scanf("%d %d %d", &length, &width, &height);

    int grossFootage = 2 * height * (length + width);
    printf("\nYou entered the following dimensions:");
    printf("\n%2d feet long", length);
    printf("\n%2d feet wide and", width);
    printf("\n%2d feet high", height);
    printf("\nwhich generates %d square feet of wall space.", grossFootage);

    return grossFootage;
}

int calculateDoorsWindows()
{
    printf("\n************************************************************");
    printf("\nPlease enter the number of standard doors and standard");
    printf("\nwindows separated by a space.");
    printf("\nFor example, if you have one door and three windows,");
    printf("\nenter 1 3");
    printf("\nAll numbers should be positive \n-->");

    int doors, windows;
    scanf(" %d %d", &doors, &windows);

    int doorsWindows = (doors * DOORS_AREA + windows * WINDOWS_AREA);
    printf("\nYou entered %2d doors and %2d windows,", doors, windows);
    printf("\nwhich generates %4d of wall space area that is not painted", doorsWindows);

    return doorsWindows;
}

void displayTermination()
{
    printf("\n************************************************************");
    printf("\nProgram Terminating");
    printf("\n************************************************************\n");
}
