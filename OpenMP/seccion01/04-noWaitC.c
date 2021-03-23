#include <omp.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void nowait_example2(int n, float *a, float *b, float *c, float *y, float *z) {
	int i;
#pragma omp parallel
	{	
#pragma omp for schedule(static) nowait
 	for (i=0; i<n; i++)
		c[i] = (a[i] + b[i]) / 2.0f;
#pragma omp for schedule(static) nowait
 	for (i=0; i<n; i++)
 		z[i] = sqrtf(c[i]);
#pragma omp for schedule(static) nowait
	for (i=1; i<=n; i++)
 		y[i] = z[i-1] + a[i];
 	}
}

void Init_col(int n, float *a, float * b, float * c, float * d, float * e){
  int j;

  for (j=0; j<n; j++){
	  a[j] = 2.1*j;
	  b[j] = 1.2*j;
	  c[j] = 4.1*j;
	  d[j] = 2.3*j;
	  e[j] = 6.7*j;
	  //printf("--%f \n", a[j]);
	}
}

int main (int argc, char **argv)
{
  	int  N;
  	N  = (int) atof(argv[1]); argc--; argv++;
	float* ptrV0; 
	float* ptrV1; 
	float* ptrV2; 
	float* ptrV3; 
	float* ptrV4; 
	ptrV0 = (float*)malloc(N * sizeof(float));
	ptrV1 = (float*)malloc(N * sizeof(float));
	ptrV2 = (float*)malloc(N * sizeof(float));
	ptrV3 = (float*)malloc(N * sizeof(float));
	ptrV4 = (float*)malloc(N * sizeof(float));

	Init_col(N, ptrV0, ptrV1, ptrV2, ptrV3, ptrV4);

	nowait_example2(N, &ptrV0[0],  &ptrV1[0],  &ptrV2[0],  &ptrV3[0], &ptrV4[0]); 

	return 0;
}
