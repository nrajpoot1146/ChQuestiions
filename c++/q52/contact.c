#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
* save contact to file contact.txt
* @param filename of data
*/
void Save(char *fileName);

/**
* update existing contact phone number
* read name and surname
* update phone number
* @param filename of data
*/
void Update(char *fileName);

/**
* read name
* show phone number
* @param filename of data
*/
void Call(char *fileName);

/**
* read name
* read surname
* delete contact with name and surname
* @param filename of data
*/
void Delete(char *fileName);

/**
* show menu
*
*/
void menu();

int main(){

    char *fileName = "contact.txt";

    while (1){
        printf("\n");
        menu();
        int op;
        scanf("%d", &op);

        if(op == 5){
            break;
        }

        switch(op){
        case 1:
            Save(fileName);
            break;
        case 2:
            Update(fileName);
            break;
        case 3:
            Call(fileName);
            break;
        case 4:
            Delete(fileName);
            break;
        default:
            printf("");
        }
    }
}

void Save(char *fileName){
    // open file and get file pointer
    FILE *f = fopen(fileName, "a+");
    char name[50];
    char surname[50];
    char phoneNumber[50];

    // read name
    printf("Enter first name: ");
    scanf("%s", name);

    // read surname
    printf("Enter surname: ");
    scanf("%s", surname);

    // read phone number
    printf("Enter phone number: ");
    scanf("%s", phoneNumber);

    // save all details to data file
    fputs(name, f);
    fputs(",", f);
    fputs(surname, f);
    fputs(",", f);
    fputs(phoneNumber, f);
    fputs("\n", f);

    // close current file
    fclose(f);
}

void Update(char* fileName){
    // open file and get file pointer
    FILE *f = fopen(fileName, "a+");

    // open temporary file
    FILE *ftemp = fopen("temp.txt", "a+");

    char line[1000];

    char name[50];
    char surname[50];

    // read name
    printf("Enter name: ");
    scanf("%s", name);

    // read surname
    printf("Enter surname: ");
    scanf("%s", surname);

    while ( fgets(line, 1000, f) != NULL){ // read line from file
        char *Cname = strtok(line, ","); // fetch name from line
        char *Csurname = strtok(NULL, ", "); // fetch surname from line
        char *CphnNo = strtok(NULL,""); // fetch phone number from line

        fputs(Cname, ftemp); // put name to file
        fputs(",", ftemp); // put comma to file
        fputs(Csurname, ftemp); // put surname to file
        fputs(",", ftemp); // put comma to file

;        if (strcmp(Cname, name) == 0 && strcmp(Csurname, surname) == 0){ // compare name and surname with contact details
            // if matched update phone number
            char phnNo[50];
            printf("Enter Phone number: ");
            scanf("%s", phnNo);

            printf("Phone updated successfully.\n");
            // put phone number to file
            fputs(phnNo, ftemp);
        }else{
            // put phone number to file
            fputs(CphnNo, ftemp);
        }

    }
    // close contact.txt file
    fclose(f);
    // close temp.txt file
    fclose(ftemp);

    // delete old file
    remove(fileName);
    // rename temp.txt tp contact.txt
    rename("temp.txt",fileName);
}

void Call(char* fileName){
    FILE *f = fopen(fileName, "r");

    char line[1000];

    char name[50];

    printf("Enter name: ");
    scanf("%s", name);

    while ( fgets(line, 1000, f) != NULL){
        char *token = strtok(line, ",");

;        if (strcmp(token, name) == 0){
            token = strtok(NULL, ", ");
            token = strtok(NULL, "");
            printf("Phone number: %s", token);
            fclose(f);
            return;
        }

    }
    printf("Error: contact not available.\n");
    fclose(f);
}

void Delete(char *fileName){
    FILE *f = fopen(fileName, "a+");

    FILE *ftemp = fopen("temp.txt", "a+");

    char line[1000];

    char name[50];
    char surname[50];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter surname: ");
    scanf("%s", surname);

    while ( fgets(line, 1000, f) != NULL){
        char *Cname = strtok(line, ",");
        char *Csurname = strtok(NULL, ", ");
        char *CphnNo = strtok(NULL,"");


;        if (strcmp(Cname, name) == 0 && strcmp(Csurname, surname) == 0){
            continue;
        }else{
            fputs(Cname, ftemp);
            fputs(",", ftemp);
            fputs(Csurname, ftemp);
            fputs(",", ftemp);
            fputs(CphnNo, ftemp);
        }

    }
    fclose(f);
    fclose(ftemp);

    // delete old file
    remove(fileName);
    // rename temp.txt tp contact.txt
    rename("temp.txt",fileName);
}

void menu(){
    printf("1) Save\n");
    printf("2) Update\n");
    printf("3) Call\n");
    printf("4) Delete\n");
    printf("5) Exit\n");
}
