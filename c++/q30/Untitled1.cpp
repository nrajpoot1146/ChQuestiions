#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* A structure to represent a single point 2D space*/

typedef struct Point{
	int x;
	int y;
}Point2D;

/*
* function to take points from user
*/
Point2D* GetPointsFromUser(int count){
	static Point2D *points = (Point2D*) malloc(count * sizeof(Point2D)); // memory allocation for points variable
	int x,y;
	for (int i=0; i<count; i++){
		printf("Enter point %d in (x, y): ", i);
		scanf("%d %d",&x,&y); // get value of x and y from user
		points[i].x = x;
		points[i].y = y;
	}
	return points;
}

/**
 * function to print a single point
 */
void PrintPoint(Point2D* pPoint){
	printf("x = %d, y = %d\n",pPoint->x,pPoint->y);
}

/**
 * function to print a array of points
 */
void PrintPoints(Point2D* pPoints, int size){
	for(int i = 0; i<size; i++){
		printf("x = %d, y = %d\n", pPoints[i].x, pPoints[i].y);
	}
}

/**
 * function to calculate Euclidean distance between two points
 */
double EuclideanDistance(Point2D *pt1, Point2D *pt2){
	double res = sqrt(pow( (pt1->x - pt2->x), 2 ) + pow( (pt1->y - pt2->y), 2 ));
	return res;
}

/**
 * function to print index of two closest points of a given point array
 */
void FindClosestPoints(Point2D *pPoints, int size){
	int index1, index2;
	double min;
	for(int i=0; i < size-1; i++){
		for(int j = i+1; j<size; j++){
			double d = EuclideanDistance(&pPoints[i], &pPoints[j]);
			if(i == 0 && j == i+1){
				index1 = i;
				index2 = j;
				min = d;
			}else{
				if(min > d){
					index1 = i;
					index2 = j;
					min = d;
				}
			}
		}
	}
	
	printf("point at index %d and point at index %d are closer\n",index1,index2);
}

/**
 * fucntion to print index of two duplicates points from given array
 */
void PrintDuplicates(Point2D* pPoints, int size){
	for(int i=0; i<size-1; i++){
		for(int j = i+1; j<size; j++){
			if(pPoints[i].x == pPoints[j].x && pPoints[i].y == pPoints[i].y){
				printf("point at index %d and point at index %d are same\n", i, j);
			}
		}
	}
}

/**
 * driver code
 */
int main(){
	Point2D* pPoints;
	int point_count = 0;
	
	printf("Enter point count please: ");
	scanf("%d", &point_count);
	pPoints = GetPointsFromUser(point_count);
	PrintPoints(pPoints, point_count);
	FindClosestPoints(pPoints, point_count);
	return 0;
}
