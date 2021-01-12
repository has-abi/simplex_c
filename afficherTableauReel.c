/*
Author: Abida Hassan
Filier: SDAD
*/
#include<stdio.h>

void afficherTableauReel(double *T,int N)
{
	
	int i;
	for(i = 1;i <= N;i++)
		printf("%14.12f ",*(T+i));
	
	printf("\n");
	
}
