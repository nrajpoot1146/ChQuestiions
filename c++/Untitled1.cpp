#include<stdlib.h>
typedef struct circleroute
{
    //Coordinate *point; //This is simply another module with another struct which compiles without any error
    char *name;
} Circle;

Circle *circlemalloc(int nroutes){
	return (Circle*) malloc(nroutes*sizeof(Circle));
} //error free
//Circle *readRoute(FILE *fin);      //error free

int main(int argc, char *argv[])
{
	Circle *c ;//= malloc(sizeof(Circle));
	struct circleroute t;
	c = &t;
//    if (argc < 2)
//    {
//        if (argv[1] != NULL)
//        {
//            FILE *fin = fopen(argv[1], "r");
//            if (fin == NULL)
//            {
//                printf("Unable to open file %s!\n", argv[1]);
//                return EXIT_FAILURE;
//            }
//            int routes;
//            fscanf(fin, "%d", &routes);
//            Circle *c1 = circlemalloc(routes);
//            for (int i = 0; i < routes; i++)
//            {
//                c1[i] = readRoute(fin); //This gives me an error saying incompatible types when assigning to type Circle from type struct Circle *
//            }
//        }
//    }
}
