#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void pixelThreshold(float *r, float *g, float * b){
    if(*r > 0.5){
        *r = 1;
        *g = 1;
        *b = 1;
    }else{
        *r = 0;
        *g = 0;
        *b = 0;
    }
}

int main(){
    float image[4][4][3];
    int x, y;
    srand(0);

    for(y=0; y<4; y++){
        for(x=0; x<4; x++){
            image[x][y][0] = (float) rand() / (float) RAND_MAX;
            image[x][y][1] = (float) rand() / (float) RAND_MAX;
            image[x][y][2] = (float) rand() / (float) RAND_MAX;
        }
    }

    for(y=0; y<4; y++){
        for(x=0; x<4; x++){
            pixelThreshold(&image[x][y][0], &image[x][y][1], &image[x][y][2]);
        }
    }


    for(y=0; y<2; y++){
        for(x=0; x<4; x++){
            printf("%d %d: %1.6f %1.6f %1.6f\n",x,y,image[x][y][0],image[x][y][1],image[x][y][2]);
        }
    }

    return 0;
}
