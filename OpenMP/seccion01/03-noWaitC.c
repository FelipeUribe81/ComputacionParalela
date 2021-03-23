#include <omp.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void nowait_example(int n, int m, float *a, float *b, float *y, float *z)
{
int i;
#pragma omp parallel
{
	#pragma omp for nowait
	for (i=1; i<n; i++){
		b[i] = (a[i] + a[i-1]) / 2.0;
		//printf("%f \n", b[i]);
	}

	#pragma omp for nowait
	for (i=0; i<m; i++)
		y[i] = sqrt(z[i]);
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
  	int  N, M;
  	N  = (int) atof(argv[1]); argc--; argv++;
	M = N*100;
	float* ptrV0; 
	float* ptrV1; 
	float* ptrV2; 
	float* ptrV3; 
	ptrV0 = (float*)malloc(N * sizeof(float));
	ptrV1 = (float*)malloc(N * sizeof(float));
	ptrV2 = (float*)malloc(M * sizeof(float));
	ptrV3 = (float*)malloc(M * sizeof(float));

	Init_col(N, ptrV0, ptrV1);
	Init_col(M, ptrV2, ptrV3);

	nowait_example(N, M, &ptrV0[0],  &ptrV1[0],  &ptrV2[0],  &ptrV3[0]); 

	return 0;
}
