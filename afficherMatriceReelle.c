/*
Author: Abida Hassan
Filier: SDAD
*/
#include<stdio.h>

void afficherMatriceReelle(double **A,int L,int C)
{
	int i,j;
	for(i = 1;i<=L;i++)
           {
	     for(j = 1;j<=C;j++)
		printf("%f  ",*(A[i]+j));
	     printf("\n");
	   }
}
