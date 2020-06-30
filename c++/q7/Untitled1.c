#include<stdio.h>

int main(){
    int i = 0, sum = 0, cnt = 0;
    int egnAvg = 0;
    int marks[5];
    for(i=0; i<5; i++){
        printf("Enter Mark ");
        scanf("%d", &marks[i]);
    }

    for(i=0; i< 5; i++){
        sum += marks[i];
    }

    egnAvg = sum / 5;

    printf("The marks entered are : \n");

    for(i=0; i<5; i++){
        if(marks[i] >= egnAvg)
            cnt++;
        printf("%d ",marks[i]);
    }
    printf("\n");
    printf("Sum = %d\n",sum);
    printf("Average EGN 2712 is : %d\n",egnAvg);
    printf("Number of marks above average is %d",cnt);
}
