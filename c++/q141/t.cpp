/************************* Author: Mainak Chaudhuri ************************
 * Reference: Rafael H. Saavedra-Barrera. PhD dissertation. University of California, Berkeley, 1992.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX (1 << 26)
#define ACCESS (1 << 30)

int main(void)
{
   int *v = new int[MAX], *u = new int[MAX];
   register int i, limit, k;
   double start, stop;
   printf("f");
   FILE *fp = fopen("download.log","w+");
   int logsize = 11, logstride = 5, stride, j, size;

   for (size = (1 << logsize); size <= MAX; size *= 2) {
	stride = 1 << logstride;	// The 128-byte stride is chosen after some
					// experimentation to bring out the capacity
					// jumps prominently.
        for (i=0; i<size; i+=stride) {
           v[i] = (i+stride) % size;
        }
        for (i=0; i<MAX; i++) u[i] = 0;
        limit = (ACCESS >> logsize)<<logstride;
        k = 0;
        start = (double)clock()/CLOCKS_PER_SEC;
        for (i=0; i<limit; i++) {
            do {
               k = v[k];
            } while (k!=0);
        }
        stop = (double)clock()/CLOCKS_PER_SEC;
        fprintf(fp, "%10d%10d%10lf\n", size*sizeof(v[0]), stride*sizeof(v[0]), stop-start);
        logsize++;
   }
   
   fclose(fp);
   printf("Value: %d\n", u[rand()%MAX]);
   return 0;
} 