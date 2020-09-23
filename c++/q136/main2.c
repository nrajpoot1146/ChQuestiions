#include <stdio.h>
#include <string.h>

/**
 * subject structure to store details of subject
 */
struct Subject{
    int Sub_Id;       // subject id;
    char Sub_Name[30];  // subject name;
    double marks;       // subject marks 
};

// redefine subject datatype
typedef struct Subject subject;

/**
 * Student structure to store student details
 */
struct Student
{
    int Stude_Id;       // student id;
    char Stu_Name[30];  // student name;
    subject sub[3];       // student marks
};

// redefine student datatype
typedef struct Student student;

void main()
{
    // declare an array of five students
    student s;

    // read student details
    printf("Enter student id: ");
    scanf("%d", &s.Stude_Id);
    printf("Enter student name: ");
    scanf("%s", s.Stu_Name);

    for (int i=0; i<3; i++) {
        printf("\tEnter subject id: ");
        scanf("%d", &s.sub[i].Sub_Id);
        printf("\tEnter subject name: ");
        scanf("%s", s.sub[i].Sub_Name);
        printf("\tEnter subject marks: ");
        scanf("%d", &s.sub[i].marks);
    }
    
    // print student details
    printf("Student id: %d\n", s.Stude_Id);
    printf("Student name: %s\n", s.Stu_Name);

    for (int i=0; i<3; i++) {
        printf("\tSubject id: %d\n", s.sub[i].Sub_Id);
        printf("\tSubject name: %s\n", s.sub[i].Sub_Name);
        printf("\tSubject marks: %d\n", s.sub[i].marks);
    }
}