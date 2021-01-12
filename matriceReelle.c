/*
Author: Abida Hassan
Filier: SDAD
*/
#include<stdio.h>
#include<stdlib.h>

double** matriceReelle(int L,int C)
{

	double* tableauReel(int N);
	int i;
	double **A;
	A = (double**) malloc(L*sizeof(double*));
	if(A == NULL)
          {
		printf("matriceReelle: pas assez de memoire");
		exit(-1);
	   }
	A--;
	for(i = 1;i<=L;i++)
           A[i]= tableauReel(C);
           
	return A;
}
