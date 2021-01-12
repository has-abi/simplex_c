/*
Author: Abida Hassan
Filier: SDAD
*/
#include<stdlib.h>

void libererMatriceReelle(double** A,int L, int C)
{
	void libererTableauReel(double *T, int N);
        int i;
	for(i = 1;i<=L;i++)
	   libererTableauReel(A[i], C);	
		
	free(A++);
}
