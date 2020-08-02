// ------------------------------------------------------------------------------------------
// Includes
// ------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

// ------------------------------------------------------------------------------------------
// Constants
// ------------------------------------------------------------------------------------------
const long longARRAY_SIZE = 100;

// ------------------------------------------------------------------------------------------
// User Defined Types (UDT)
// ------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------
// Prototypes
// ------------------------------------------------------------------------------------------
void MakeArray(int** ppaintMiles, int* pintArraySize);
void InitializeArray(int* paintMiles, int intArraySize);
void PopulateArray(int* paintMiles, int intArraySize);
void PrintArray(char* pstrMilesEntered, int* paintMiles, int intArraySize);
void AddNewDay(int* ppaintMiles, int* pintArraySize);

// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
void main()
{
   int intIndex = 0;
   int intArraySize = 0;
   int* paintMiles = 0;
   int intResult = 0;


   printf("This application will track daily miles that the use has run.\n");

   MakeArray(&paintMiles, &intArraySize);

   InitializeArray(paintMiles, intArraySize);

   PopulateArray(paintMiles, intArraySize);

   AddNewDay(paintMiles, &intArraySize);

   PrintArray("-Miles Logged Per Day--------", paintMiles, intArraySize);




   system("pause");
}

// ------------------------------------------------------------------------------------------
// Name: MakeArray
// Abstract: allocate space for one array entry - use malloc
// ------------------------------------------------------------------------------------------
void MakeArray(int** ppaintMiles, int* pintArraySize)
{
   int intDayOne = 1;

   *pintArraySize = intDayOne;

   // Create array dynamically
   *ppaintMiles = (int*)malloc(sizeof(int) * *pintArraySize);
}

// ------------------------------------------------------------------------------------------
// Name: InitializeArray
// Abstract: Create Array
// ------------------------------------------------------------------------------------------
void InitializeArray(int* paintMiles, int intArraySize)
{
   int intIndex = 0;

       for (intIndex = 0; intIndex < intArraySize; intIndex += 1)
       {
           *(paintMiles + intIndex) = 0;
       }
       printf("\n");
}



// ------------------------------------------------------------------------------------------
// Name: PopulateArray
// Abstract: collect first entry from user
// ------------------------------------------------------------------------------------------
void PopulateArray(int* paintMiles, int intArraySize)
{
   int intIndex = 0;

   printf("-Daily Miles Tracker--------------\n");
   for (intIndex = 0; intIndex < intArraySize; intIndex += 1)
   {
       printf(" Enter number of miles run on day [%d]: ", intIndex + 1);
       scanf("%d", (paintMiles + intIndex));
   }
   printf("\n");
}

// ------------------------------------------------------------------------------------------
// Name: PrintArray
// Abstract: print contents of array when user enters -1
// ------------------------------------------------------------------------------------------
void PrintArray(char* pstrMilesEntered, int* paintMiles, int intArraySize)
{
   int intIndex = 0;
   int paintNewMiles = 0;

   //if (*paintNewMiles == -1) removed line
   //{ removed line
    printf("%s\n", pstrMilesEntered);
    for (intIndex = 0; intIndex < intArraySize; intIndex += 1)
    {
        paintNewMiles = *(paintMiles + intIndex);
        if (paintNewMiles == -1)
            break;
        printf(" Miles for Day [ %d ] = %d\n", intIndex + 1, paintNewMiles);
    }
   //} removed line
   printf("\n");
}

// ------------------------------------------------------------------------------------------
// Name: AddNewDay
// Abstract: allow user to add more entries until they enter -1
// ------------------------------------------------------------------------------------------
void AddNewDay(int* ppaintMiles, int* pintArraySize)
{
   int* paintNewMiles = 0;

   printf(" Enter current day's miles, enter '-1' when finished.\n");

    do{
        (*pintArraySize)++;
        paintNewMiles = (int *) realloc(ppaintMiles, *pintArraySize);
        printf(" Enter number of miles run on day [%d]: ", *pintArraySize);
        scanf("%d", (paintNewMiles + (*pintArraySize) - 1));
    } while(*(paintNewMiles + (*pintArraySize) - 1) != -1);

    ppaintMiles = paintNewMiles;

}
