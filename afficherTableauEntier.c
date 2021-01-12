/*
Author: Abida Hassan
Filier: SDAD
*/
#include<stdio.h>

void afficherTableauEntier(int *T,int N)
{
	
	int i;
	for(i = 1;i <= N;i++)
		printf("%d ",*(T+i));
	
	printf("\n");
	
}
