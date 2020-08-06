#include <cstdio>
#include <cstdlib>

// calculate transpose of a matrix
// return transpose of given matrix
int** transpose(int **m, const int &N, const int &M){
	int **res = (int **) malloc (sizeof(int*) * M);
	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++){
			if (i == 0){
				res[j] = (int *) malloc(sizeof(int) * N);
			}
			res[j][i] = m[i][j];
		}
	}
	free(m);
	return res;
}

// perform single left rotation on given matrix
// return rotated matrix
int** lRotate(int **m, const int &N, const int &M){
	int **res = (int **) malloc (sizeof(int*) * M);
	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++){
			if (i == 0){
				res[M-1-j] = (int *) malloc(sizeof(int) * N);
			}
			res[M-1-j][i] = m[i][j];
		}
	}
	free(m);
	return res;
}

// perform right rotation on matrix
// return right rotated matrix
int** rRotate(int **m, const int &N, const int &M){
	int **res = (int **) malloc (sizeof(int*) * M);
	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++){
			if (i == 0){
				res[j] = (int *) malloc(sizeof(int) * N);
			}
			res[j][N-1-i] = m[i][j];
		}
	}
	free(m);
	return res;
}
//
// print given matrix
void printMatrix(int **m, const int &N, const int &M){
	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++){
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}
}

// swap given two integers
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int main(void){
	int k;
	int N, M;
	char commands[50];
	scanf("%d", &k); // read number of testcases
	for (int i=0; i<k; i++){
		scanf("%d%d", &N, &M);
		int **m = (int **) malloc (sizeof(int*) * N);;
		for (int i=0; i<N; i++){
			m[i] = (int *) malloc(sizeof(int *) * M);
			for (int j=0; j<M; j++){
				scanf("%d", &m[i][j]);
			}
		}
	
		scanf("%s",commands); // read command string
		
		
		for (int i=0; commands[i] != '\0'; i++){
			char c = commands[i];
			if (c == 'T'){
				m = transpose(m, N, M); // perform transpose
				swap(N, M);
			} else if (c == 'L'){
				m = lRotate(m, N, M); // perform left rotation
				swap(N, M);
			} else if (c == 'R'){
				m = rRotate(m, N, M); // perform right rotation
				swap(N, M);
			}
		}
		
		printf("\n");
		printMatrix(m, N, M); // print resultant matrix
	}
	system("pause");
}
