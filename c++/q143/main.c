#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    int id;
    char *name;
} student;

typedef struct school
{
    int nstudents;
    student **student_ptr2;
} school;

int main(void)
{
    student *student_ptr1;

    student_ptr1 = calloc(3, sizeof(struct student));
    (student_ptr1 + 0)->name = strdup("Danny");
    (student_ptr1 + 1)->name = strdup("Becca");
    (student_ptr1 + 2)->name = strdup("Harold");
    (student_ptr1 + 0)->id = 1234;
    (student_ptr1 + 1)->id = 3456;
    (student_ptr1 + 2)->id = 5678;

    for (int i = 0; i < 3; i++)
    {
        printf("student_list #%d %s id: %d\n", (i + 1), (*(student_ptr1 + i)).name, (*(student_ptr1 + i)).id);
        // is equal to (i + 1), (student + i)->name, (student + i)->id)
    }

    int i = 0;
    school *school_ptr;
    struct student **student_ptr2;

    school_ptr = calloc(2, sizeof(school_ptr)); //need to point school somewhere before dereferencing.
    school_ptr->student_ptr2 = calloc(2, sizeof(student_ptr1));
    school_ptr->student_ptr2[0] = malloc(sizeof(student));
    school_ptr->student_ptr2[1] = malloc(sizeof(student));
    school_ptr->student_ptr2[i]->name = strdup("Frank"); //segmentation fault

    printf("school->student_ptr aka student **student_ptr %s", (*(school_ptr->student_ptr2 + 0))->name);
    //dereferencing a double pointer from a pointer struct
    // is equal to: school_ptr->student_ptr[i]->name, & (*(*((*school_ptr).student_ptr + i))).name
    
    // Go through the students in the school
    for(int i = 0; i < 2; i++)
    {
        strcpy((*(school_ptr->student_ptr2) + i)->name, (student_ptr1 + i)->name); // old: strcpy((*(school_ptr->student_ptr2) + i)->name, (*(student_ptr1 + i)->name);
        // Go through all the students listed
        for(int j = 0; j < 3; j++)
        {
            if(strcmp((*(school_ptr->student_ptr2) + i)->name, (student_ptr1+ j)->name) == 0) // old:  if(strcmp((*(school_ptr->student_ptr) + i)->name, (*(student_ptr1+ j)->name)) == 0)
            {
                // Set the students to the school if they match
                school_ptr->student_ptr2[i] = (student_ptr1 + i);
            }
        }
    }

    free(student_ptr1->name);
    free(student_ptr1);
    free(school_ptr);
    free(school_ptr->student_ptr2);

    return 0;
}