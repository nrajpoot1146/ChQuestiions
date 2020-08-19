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

double cal_avg_salary(employee emp, int year) {
    if (year < emp.servedYear) {
        return -1; // return -1 if year is < served year
    }
    int t_diff = year - emp.servedYear; // calculate number of year
    int i_amount = t_diff * 5000; // calculate increased amount (increase 5k per year)
    int p_amount = emp.nOfProject * 10000; // calculate total project bonus

    double total_increment = (i_amount + p_amount) / 12.0; // calculate average increment per month
    double avg_salary = emp.initialSalary + total_increment; // calculate average salary per month
    return avg_salary; // return salary
}

void main() {
    employee emp1, emp2, emp3; // declare three employee

    // set all attribute of employee one
    strcpy(emp1.name, "John");
    emp1.servedYear = 1993;
    emp1.nOfProject = 3;
    emp1.initialSalary = 10000;

    // set all attribute of employee two
    strcpy(emp1.name, "mohan");
    emp2.servedYear = 1996;
    emp2.nOfProject = 2;
    emp2.initialSalary = 10000;

    // set all attribute of employee three
    strcpy(emp1.name, "Ram");
    emp3.servedYear = 2000;
    emp3.nOfProject = 1;
    emp3.initialSalary = 10000;


    // print average salary of all three employee
    double emp1_avg_salary = cal_avg_salary(emp1, 2020);
    printf("Average salary of employee 1: %6.2lf\n", emp1_avg_salary);

    double emp2_avg_salary = cal_avg_salary(emp2, 2020);
    printf("Average salary of employee 2: %6.2lf\n", emp2_avg_salary);

    double emp3_avg_salary = cal_avg_salary(emp3, 2020);
    printf("Average salary of employee 3: %6.2lf\n", emp3_avg_salary);
}
