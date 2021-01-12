/*
Author: Abida Hassan
Filier: SDAD
*/
#include<stdlib.h>
#include<stdio.h>
void remplirTableauReel(double *T, int N,FILE *pfichier)
{
	
	int i;
	for(i = 1;i<=N;i++)
	   fscanf(pfichier,"%lf",(T+i));
	
}
