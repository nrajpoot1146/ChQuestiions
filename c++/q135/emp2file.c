#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to store employee data
struct Employee {
    char name[20]; // char array to store name of employee
    unsigned int servedYear; // served year of employee
    unsigned int nOfProject; // no of project per year
    double initialSalary; // initial salary of employee per month
};

typedef struct Employee employee; // use typedef to give new type name

void main() {
    employee emp[3]; // create array of three employee
    int i=0;

    // set all attribute of employee one
    strcpy(emp[0].name, "John");
    emp[0].servedYear = 1993;
    emp[0].nOfProject = 3;
    emp[0].initialSalary = 10000;

    // set all attribute of employee two
    strcpy(emp[1].name, "mohan");
    emp[1].servedYear = 1996;
    emp[1].nOfProject = 2;
    emp[1].initialSalary = 10000;

    // set all attribute of employee three
    strcpy(emp[2].name, "Ram");
    emp[2].servedYear = 2000;
    emp[2].nOfProject = 1;
    emp[2].initialSalary = 10000;


    // open output file
    FILE *f = fopen("out.txt", "w");
    for (i=0; i<3; i++) {
        // write data to output file
        fprintf(f,"%s\n%d\n%d\n%6.2lf",emp[i].name,emp[i].servedYear,emp[i].nOfProject,emp[i].initialSalary);
        if(i+1 != 3) {
            fprintf(f,"\n");
        }
    }
    fclose(f); // close output file

    // open out.txt file to read data
    FILE *fRead = fopen("out.txt", "r");

    for (i=0; i<3; i++) {
        char name[20];
        int servedYear;
        int nOfProject;
        double initialSalary;

        fscanf(f,"%s\n%d\n%d\n%lf",name,&servedYear,&nOfProject,&initialSalary); // read data from file
        if(i+1 != 3) {
            fscanf(f,"\n");
        }
        //print read data to console
        printf("Name: %s\nServed Year: %d\nNumber of project: %d\nInitial Salary: %6.2lf\n\n",name,servedYear,nOfProject,initialSalary);

    }
    // close file
    fclose(fRead);
}
