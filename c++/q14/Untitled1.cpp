#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//hash table structure
struct hashTable{
    int isChecked;
    char data[50];
};
int N,M,K;
int numElement = 0;
struct hashTable *ht;

//function to print hash table
void printTable(){
    int i=0;
    while(i<M){
        printf("%d: %s\n",i,ht[i].data);
        i++;
    }
}

//function to map char value to integer value;
int chr(char c){
    if(c>='a' && c<='z'){
        return c-'a';
    }else if(c>='A' && c<='Z'){
        return 26+c-'A';
    }else{
        return 52+c-'0';
    }
}

//function to extend the hash table
void grow(){
    struct hashTable* temp = (struct hashTable*) malloc(sizeof(struct hashTable)*M*2);
    int i=0;
    while(i<M*2){
        temp[i].isChecked = 0;
        strcpy(temp[i].data,""); //assign all string to empty string;
        i++;
    }
    M = M * 2;
    ht = temp;
};

//function to convert decimal number to binary number
char *decToBinary(int n)
{
    // array to store binary number
    static char binaryString[6];

    // counter for binary array
    int i = 5;
    while (i>=0) {

        // storing remainder in binary array
        binaryString[i] = (n % 2)+'0';
        n = n / 2;
        i--;
    }

    return binaryString;
}

//function to calculate mod value of any large binary string
int getMod(char *str)
{
    int n = strlen(str);
    // pwrTwo[i] will store ((2^i) % k)
    int pwrTwo[n];
    pwrTwo[0] = 1 % M;
    for (int i = 1; i < n; i++)
    {
        pwrTwo[i] = pwrTwo[i - 1] * (2 % M);
        pwrTwo[i] %= M;
    }

    // To store the result
    int res = 0;
    int i = 0, j = n - 1;
    while (i < n)
    {

        // If current bit is 1
        if (str[j] == '1')
        {

            // Add the current power of 2
            res += (pwrTwo[i]);
            res %= M;
        }
        i++;
        j--;
    }
    return res;
}

//function to calulate hash value of string
int calHash(char *str){
    int i=0;
    //printf("%s\n",str);
    int len = strlen(str);
    char* binaryString = (char*) malloc(6*len);
    while(binaryString == NULL){
        printf("not\n");
        binaryString = (char*) malloc(6*len);
    }
    strcpy(binaryString,"");

    while(i<len){
        strcat(binaryString, decToBinary(chr(str[i])));
        i++;
    }
    int mod = getMod(binaryString);
    free(binaryString);
    return mod;
}

//function to insert value in hash table
int insert(char str[][50]){

    int i = 0;
    while(i<N){
        int hash = calHash(str[i]);
        if(strlen(ht[hash].data) != 0){
            hash = (hash+K)%M;
            while(strlen(ht[hash].data) != 0){
                if(ht[hash].isChecked != 0){
                    return 0;
                }
                ht[hash].isChecked = 1;
                hash = (hash+K) % M;
            }
        }

        numElement++;
        strcpy(ht[hash].data,str[i]);
        i++;
    }

    return 1;
}

//driver function
int main(){
    int i=0;
    scanf("%d %d %d",&N,&M,&K);

    char str[N][50];
    ht = (struct hashTable*) malloc(sizeof(struct hashTable)*M);

    while(i<M){
        ht[i].isChecked = 0;
        strcpy(ht[i].data,"");
        i++;
    }

    i=0;
    while(i<N){
        scanf("%s",str[i]);
        i++;
    }

    while(insert(str) != 1){
        int j=0;
        int k=0;
        while(j<numElement){
            while(strlen(ht[k].data) ==0 ){
                k++;
            }
            strcpy(str[j],ht[k].data);
            k++;
            j++;
        }
        numElement = 0;
        grow();
    }


    printTable(); //print hash table
}

