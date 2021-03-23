#include <omp.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

float average(float x,float y, float z){
	int i;
	float sum = 0, prom = 0; 
        sum = x + y + z;
	if (sum == 0) 
		printf("Error división por cero \n");
else 
		prom = sum/3;
	
	return prom;
}


void master_example( float* x, float* xold, int n, float tol) {
int c, i, toobig;
float error, y;
c = 0;
#pragma omp parallel
{
	do{
#pragma omp for private(i)
		for( i = 1; i < n-1; ++i ){
			xold[i] = x[i];
		}
#pragma omp single
		{
			toobig = 0;
		}
#pragma omp for private(i,y,error) reduction(+:toobig)
		for( i = 1; i < n-1; ++i ){
			y = x[i];
			x[i] = average( xold[i-1], x[i], xold[i+1]);
			error = y - x[i];
			if( error > tol || error < -tol ) ++toobig;
		}
#pragma omp master
		{
		++c;
		printf( "iteration %d, toobig=%d\n", c, toobig );
		}	
	}while( toobig > 0 );
   }
}

void Init_col(int n, float *a, float * b){
  int j;

  for (j=0; j<n; j++){
	  a[j] = 2.1*j;
	  b[j] = 1.2*j;
	  //printf("--%f \n", a[j]);
	}
}

int main (int argc, char **argv)
{
  	int  N;
  	N  = (int) atof(argv[1]); argc--; argv++;
	float* ptrV0; 
	float* ptrV1; 
	float umbral = 0.2;
	ptrV0 = (float*)malloc(N * sizeof(float));
	ptrV1 = (float*)malloc(N * sizeof(float));

	Init_col(N, ptrV0, ptrV1);

	master_example(&ptrV0[0],  &ptrV1[0],  N, umbral); 

	return 0;
}
