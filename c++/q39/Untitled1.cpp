#include<stdio.h>
#include<fcntl.h>
#include<errno.h>

extern int errno;

int myfopen(char filename[]){
	int fd = open(filename , O_RDONLY ); // try to open file with o_RDONLY
	if(fd == -1){
		printf("Error no. %d\n", errno); // print error no if any erro occur
		perror("Program"); // print error if any error occur
	}
	
	return fd;
}

int main(){
	char fileName[] = "sample.txt"; // file name
	int fileDescriptor = myfopen(fileName);
	printf("file descriptor: %d", fileDescriptor);
}
