#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person_tag{
    char name[20];
    char id[10];
};

struct course_tag{
    char course_name[20];
    int no_of_units;
    int marks[4];
    float avg;
};

struct student_tag{
    struct person_tag student_info;
    struct course_tag course_info;
    struct student_tag *next;
};

struct student_tag* read_file(){
    char fileName[] = "students.txt";
    FILE *f = fopen(fileName, "r");
    if (!f){
        return;
    }

    char line[50];
    struct student_tag *root = NULL;
    struct student_tag *last = NULL;
    while (fgets(line, 50, f) != 0){
        struct student_tag *temp = (struct student_tag*) malloc(sizeof(struct student_tag));
        strcpy(temp->student_info.name, line);
        fgets(temp->student_info.id, 10, f);
        fgets(temp->course_info.course_name, 20, f);
        temp->student_info.name[strlen(temp->student_info.name) - 1] = '\0';
        temp->student_info.id[strlen(temp->student_info.id) - 1] = '\0';
        temp->course_info.course_name[strlen(temp->course_info.course_name) - 1] = '\0';
        fscanf(f, "%d\n", &temp->course_info.no_of_units);
        
        int sum = 0,i=0;
        for (i=0; i<temp->course_info.no_of_units; i++){
        	fscanf(f, "%d\n", &temp->course_info.marks[i]);
        	sum += temp->course_info.marks[i];
		}
		
		temp->course_info.avg = ((float)sum) / temp->course_info.no_of_units;
        temp->next = NULL;

        if (last == NULL){
			root = temp;
			last = temp;
        } else {
        	
        	if (strcmp(line, root->student_info.name) <= 0){
        		temp->next = root;
        		root = temp;
			} else if (strcmp(line, last->student_info.name) >= 0){
				last->next = temp;
				last = temp;
			} else {
				struct student_tag *prev = root;
				struct student_tag *curr = root->next;
				while (strcmp(line, curr->student_info.name) > 0){
					prev = curr;
					curr = curr->next;
				}
				
				prev->next = temp;
				temp->next = curr;
			}
		}
    }

	return root;
}

// function to display menu
int menu() {
	printf("(1) Display student''s details\n");
	printf("(2) Search for a student''s mark\n");
	printf("(3) Find the details of student with the largest average\n");
	printf("(4) Find the details of failed students\n");
	printf("(5) Add new student to the record\n");
	printf("(6) Quit program\n");
	int num;
	scanf("%d", &num);
	return num;
}

// function to dispplay single student details
void display(struct student_tag *student){
	printf("%s\n", student->student_info.name);
	printf("%s\n", student->student_info.id);
	printf("%s\n", student->course_info.course_name);
	int i=0;
	for (i=0; i<student->course_info.no_of_units; i++){
		printf("%d ",student->course_info.marks[i]);
	}
	printf("\nAverage = %5.2f\n", student->course_info.avg);
}

// function to display all student details
void display_students(struct student_tag *root){
	while (root != NULL){
		display(root);
		printf("\n");
		root = root->next;
	}
}


// function to search student by name
void search_student(struct student_tag *root){
	char name[20];
	printf("Enter a name to search: ");
	scanf("%s", name);
	while (root != NULL){
		if (strcmp(root->student_info.name, name) == 0)
			display(root);
		root = root->next;
	}
	if(root == NULL){
		printf("Error: Not found\n");
	}
}


// function to find a student with maximum average
void find_maximum(struct student_tag *root){
	struct student_tag *max = root;
	root = root->next;
	while (root != NULL){
		if (max->course_info.avg < root->course_info.avg)
			max = root;
		root = root->next;
	}
	display(max);
	printf("\n");
}

// function to find a failed student
void find_failed(struct student_tag *root){
	while (root != NULL){
		int i=0;
		for ( i=0; i<root->course_info.no_of_units; i++){
			if (root->course_info.marks[i] < 50){
				display(root);
				printf ("\n");
				break;
			}
		}
		root = root->next;
	}
}

void update_file(struct student_tag *root){
	FILE *f = fopen("students.txt", "a+");
	char name[20];
	printf("Enter student name: ");
	scanf("%s",name);
	fputs(name, f);
	fputs("\n", f);
	printf("Enter student id: ");
	scanf("%s", name);
	fputs(name, f);
	fputs("\n", f);
	printf("Enter course name: ");
	scanf("%s", name);
	fputs(name, f);
	fputs("\n", f);
	int num;
	printf("Enter number of units: ");
	scanf("%d", &num);
	fprintf(f, "%d\n", num);
	int i=0;
	for (i=0; i<num; i++){
		int mark;
		printf("Enter marks %d :", i+1);
		scanf("%d", &mark);
		fprintf(f, "%d\n", mark);
	}
	fflush(f);
}



void main(){
	struct student_tag* root;
    root = read_file();
    printf("                              Welcomm\n \
	COS10007 – Developing Technical Software\n\n");
    
    while (1){
    	int op = menu();
    	if (op == 6){
    		printf("\nGood Bye");
			break;
		}
		
		if (op == 1){
			display_students(root); // call display student function
		} else if (op == 2){
			search_student(root); // call search student function
		} else if (op == 3){
			find_maximum(root); // call find_maximum function
		} else if (op == 4){
			find_failed(root); // call find_failed function
		} else if (op == 5){
			update_file(root); // call update_file function
		}
	}
}
