#include <stdio.h>
#include <string.h>

/**
 * Student structure to store student details
 */
struct Student
{
    int Stude_Id;       // student id;
    char Stu_Name[30];  // student name;
    double marks;       // student marks
};

// redefine student datatype
typedef struct Student student;

void main()
{
    // declare an array of five students
    student s[5];

    // initalize student arrray
    s[0].Stude_Id = 1;
    strcpy(s[0].Stu_Name, "John");
    s[0].marks = 80;

    s[1].Stude_Id = 2;
    strcpy(s[1].Stu_Name, "Ram");

    s[2].Stude_Id = 3;
    strcpy(s[2].Stu_Name, "Shyam");
    s[2].marks = 60;

    s[3].Stude_Id = 4;
    strcpy(s[3].Stu_Name, "Rohan");
    s[3].marks = 70;

    s[4].Stude_Id = 5;
    strcpy(s[4].Stu_Name, "Mohan");
    s[4].marks = 90;

    // print student details
    for (int i=0; i<5; i++) {
        printf("Id: %d, Name: %s, Marks: %2.2lf;\n", s[i].Stude_Id, s[i].Stu_Name, s[i].marks);
    }
}