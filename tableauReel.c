/*
Author: Abida Hassan
Filier: SDAD
*/
#include<stdio.h>
#include<stdlib.h>

double* tableauReel(int N)
{

	double *T;
	T = (double*) malloc(N*sizeof(double));
	if(T == NULL)
          {
		printf("tableauReel: pas assez de memoire\n");
		exit(-1);
	  }
	
	return T-1;
}
