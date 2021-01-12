/*
Author: Abida Hassan
Filier: SDAD
*/
#include<stdio.h>
#include<stdlib.h>

void remplirMatriceReelle(double **A, int L,int C,FILE *pfichier)
{
	int i,j;
	for(i = 1;i<=L;i++)
	   for(j=1;j<=C;j++)
	      fscanf(pfichier,"%lf",A[i]+j);
		
}
